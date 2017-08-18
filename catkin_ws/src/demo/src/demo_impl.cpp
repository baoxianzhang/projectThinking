#include <iostream>
#include "demo_impl.h"

namespace demo_namespace
{
DemoImpl::DemoImpl()
{
}

DemoImpl::~DemoImpl()
{
}

void DemoImpl::doSomething(void)
{
  std::cout << "do something!" << std::endl;
}

int DemoImpl::addTwoInt(const int a, const int b)
{
    return a+b;
}

} // END NAMESPACE
