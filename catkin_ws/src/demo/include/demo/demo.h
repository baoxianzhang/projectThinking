#ifndef DEMO_DEMO_H
#define DEMO_DEMO_H

#include <iostream>
#include <tr1/memory>

namespace demo_namespace
{

/** @brief Demo class

    Here is the longer description.
    @code
    demo_namespace::Demo demo_obj;
    int sum = demo_obj.addTwoInt(10, 10);
    ...
    @endcode
*/
class Demo
{
public:
  Demo();
  ~Demo();
  /** @brief Do something
  */
  void doSomething(void);
  /** @brief plus two int number
      @param[in] a int number for plus
      @param[in] b another int number for plus
      @return the sum of a and b
  */
  int addTwoInt(const int a, const int b);

private:
  class DemoImpl;
  //! comment before the member
  std::tr1::shared_ptr<demo_namespace::DemoImpl> demo_impl_; //!< comment in the right
};

}      // END NAMESPACE
#endif // DEMO_DEMO_H
