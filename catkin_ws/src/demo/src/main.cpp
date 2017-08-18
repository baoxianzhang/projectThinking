#include <demo/demo.h>

demo_namespace::Demo *g_demo_obj; // for portability in windows, define the pointer

int main (int argc, char** argv)
{
  g_demo_obj = new demo_namespace::Demo;
  for (std::size_t i = 0; i < 20; ++i)
  {
    g_demo_obj->doSomething();
  }
  return 0;
}
