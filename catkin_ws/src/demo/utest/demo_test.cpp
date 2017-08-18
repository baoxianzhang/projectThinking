#include "gtest/gtest.h"
#include "demo/demo.h"

TEST(AddTwoIntTest, AddTwoInt)
{
  demo_namespace::Demo test_demo;
  EXPECT_EQ(1, test_demo.addTwoInt(0, 1));
  EXPECT_EQ(100, test_demo.addTwoInt(10, 11));
  // EXPECT_EQ(21, test_demo.addTwoInt(10, 11));
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
