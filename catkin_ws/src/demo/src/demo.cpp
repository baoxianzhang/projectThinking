#include "demo_impl.h"
#include "demo/demo.h"

namespace demo_namespace
{
Demo::Demo():demo_impl_(new demo_namespace::DemoImpl)
{
  // Below is not compile ok
  // demo_impl_ = new demo_namespace::DemoImpl;
}

Demo::~Demo()
{
  // NOTE if share_ptr not need the following
  // if(demo_impl_)
  // {
  //   delete demo_impl_;
  //   demo_impl_ = NULL:
  // }
}

void Demo::doSomething(void)
{
  demo_impl_->doSomething();
}

int Demo::addTwoInt(const int a, const int b)
{
  return demo_impl_->addTwoInt(a, b);
}

} // END NAMESPACE
