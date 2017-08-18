#ifndef DEMO_DEMO_H
#define DEMO_DEMO_H

#include <iostream>
#include <tr1/memory>

namespace demo_namespace
{
class DemoImpl;
class Demo
{
public:
  Demo();
  ~Demo();
  void doSomething(void);
  int addTwoInt(const int a, const int b);

private:
  std::tr1::shared_ptr<demo_namespace::DemoImpl> demo_impl_;
};

}      // END NAMESPACE
#endif // DEMO_DEMO_H
