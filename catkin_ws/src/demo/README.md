# Demo Documentation

## Introduction
Demo project is designed as an example to demonstrate the project structure and the coding and documentation example.

Demo project folder structure is designed for the ROS package, but also suited for the normal cmake project.

### Structure
Project is organized in several folders, each for different usages.

```
demo
├── cfg
│   └── cfg.yaml
├── CMakeLists.txt
├── data
├── doc
│   └── theory.md
├── include
│   └── demo
│       └── demo.h
├── launch
│   └── demo.launch
├── model
├── msg
│   └── DemoMsg.msg
├── package.xml
├── README.md
├── rviz
│   └── demo.rviz
├── script
│   └── dependence_install.sh
├── src
│   ├── demo.cpp
│   ├── demo_impl.cpp
│   ├── demo_impl.h
│   └── main.cpp
├── srv
│   └── DemoSrv.srv
└── utest
    └── demo_test.cpp
```

+ Add the folder according the project specific.
+ Put all the configuration files which may define the parameters in the code in the cfg foder.
+ Put all input and output data to the data folder. There is a .gitignore file to ignore the data files from uploading to the git remote server.
+ Put other documentation files include the theroy or the paper in the doc folder. Theres documentation files should describe the project detailed.
+ Consider the include and src folders, there is a folder with the same name with the project in the include folder for further lib package. And src folder should contain the interface .cpp file and the implemention _impl.h and impl.cpp files. And the main.cpp should be just a example showcase.
+ Put all the launch file to the launch folder, which if defined rviz, the rviz configuration file should be put into the rviz folder.
+ Put python scripts and the 3party depends installation shell scripts in the script folder.
+ Test the code in the utest folder, and use the google unit test.
+ Put message and service type which the first letter should be capital into msg and srv folder separatly. When model exist, put the files in the model folder.

## Documentation
This part should brief describe the project.

## Dependence
| Name           |              Version |
|----------------|----------------------|
| Ubuntu         |   14.04 LTS (64 bit) |
| gcc            |                4.8.4 |
| git            |                1.9.1 |
| cmake          |               2.8.12 |
| ROS            |               indigo |
| PCL            |                  1.7 |
| OpenCV         |                2.4.x |
| boost          |               1.54.0 |
| eigen          |                3.2.0 |
| doxygen (opt.) |              1.8.6-2 |

## Compile
Clone the code:
``` sh
git clone http://xxxxx.git
```
When first time, please run the dependence_install.sh.
``` sh
catkin_build
```


## Run

``` sh
roslaunch demo demo.launch
```
