# Handling the many git repositories in ROS

ROS applications (including ours) consist of multiple packages that often (including in our case) reside in multiple repositories. This raises a couple of challenges:

* How are the required repositories checked out?
* How are we handling version-dependency between the repositories?
* How do we locally work with multiple repositories?

## Cloning/updating the required repositories

The *official* way of working with ROS is using [workspaces](http://wiki.ros.org/catkin/workspaces) that are local to a developer's computer. These would contain the catkin packages to be used in the `src` directory. The [`rosinstall`](http://wiki.ros.org/rosinstall) tool would be used to clone repositories holding packages by means of a [rosinstall file](http://docs.ros.org/independent/api/rosinstall/html/rosinstall_file_format.html).

When we started using ROS, we decided to slightly misappropriate the workspaces by making them the de-facto main repository for a project. This allowed us to include a `src/.rosinstall` file as part of the main repository. This file holds all the information on git repositories (containing one or more packages) that the project needs.

After cloning the main project repository (i.e. RS_Localization), all other required dependencies can be installed by the following two commands:

    cd RS_Localization/src
    wstool update

Note that we are not using the `rosinstall` tool, but rather its replacement `wstool`. `wstool update` will read the .rosinstall file and clone any repository defined therein and not already cloned, as well as updating (git pull) the already cloned ones.

References:

* [wstool](http://wiki.ros.org/wstool)
* [.rosinstall file format](http://docs.ros.org/independent/api/rosinstall/html/rosinstall_file_format.html)


## Handling version-dependencies in a multi-repository ROS project

**Problem**: Having multiple repositories for a project poses the question how we know which commit/revision of each repository belongs to which "version" of the project. During the early development stages, one can simply rely on the "the master is always right" approach and fix any problems as they appear. However long-term, this approach is not going to fly. As a general rule, it must be possible to reproduce the project versions. Using simply the `master` branch of each repository makes this impossible, as we won't know what the latest commit in `master` was at any given time (using the commit times is not helpful, as they are (a) not reliable and (b) local, i.e. they may have been pushed weeks later).

**Solution**: The correct solution to this dilemma is to define each sub-repository as a quasi stand-alone product. At appropriate times, a //release// will be made of that product by giving it a version number (and updating the changelog) by **tagging** the corresponding commit. By doing that, we can specify the //version// (tag) in the `.rosinstall` file of our project.


## Working with a multi-repository ROS project 

In a "normal" git-based project, entering `git status` would give you an immediate overview of local changes to the repository. In a multi-repository project, this is not working as it doesn't include the other repositories. Luckily, `wstool` provides a few helpful commands to get an overview of the entire system.

First, remember that we only have a one-layer deep level of repositories, i.e. the folder structure we use is

```
  -- project repository (i.e. RS_Localization; main git repo)
      -- src
          -- .rosinstall
          -- folder1 (1st package repository)
          -- folder2 (2nd package repository)
          -- ..
          -- folderN (n-th package repository)
```

Assuming you are in the project repository's `src` folder, the following commands are of interest:

* `wstool info` (or just `wstool`) shows you all package repositories, including their state (clean, modified, ...) and branch. Ideally the column labelled `S` should be empty.
* `wstool status` gives you a list of files (over all package repositories) that are modified/added/deleted.
* `wstool update` updates all package repositories. Don't forget to `git pull` the main project repository beforehand for the latest .rosinstall!
* `wstool foreach` runs a command in each package repository (great if e.g. you want to stash your changes in all of them at once)

Note that these apply to the package repositories only! For the main project repository, simply use `git` as usual.
