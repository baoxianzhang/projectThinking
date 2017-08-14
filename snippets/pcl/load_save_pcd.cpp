#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>

int main (int argc, char** argv)
{
  // loading pcd file
  pcl::PointCloud<pcl::PointXYZ>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZ>);
  if (pcl::io::loadPCDFile<pcl::PointXYZ> ("test_pcd.pcd", *cloud) == -1) //* load the file
  {
    PCL_ERROR ("Couldn't read file test_pcd.pcd \n");
    return (-1);
  }

  // save pcd file
  // ASCII
  pcl::io::savePCDFileASCII("test_pcd.pcd", *cloud);
  // Binary
  pcl::io::savePCDFileBinary("test_pcd.pcd", *cloud);

  return 0;
}
