int index = 10;
std::string some_path("~/");
std::stringstream ss;
ss << index;
std::string localmap_file = somepath + ss.str() + ".vtk";
