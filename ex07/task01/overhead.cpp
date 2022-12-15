#include "stopwatch.hpp"

class StaticBase {
  static int counter;
  static void myFunc() {
    counter++;
#ifdef VERBOSE
    std::cout << "Called " << typeid(*this).name() << "::" << __func__
              << std::endl;
#endif
  };
};

class PureBase {
private:
  int counter;

public:
  PureBase();
  void myFunc() {
#ifdef VERBOSE
    counter++;
    std::cout << "Called " << typeid(*this).name() << "::" << __func__
              << std::endl;
#endif
  };
};

class VirtBase {
public:
  VirtBase();
  void nvFunc();
  virtual void virtFunc() {
    counter++;
#ifdef VERBOSE
    std::cout << "Called " << typeid(*this).name() << "::" << __func__
              << std::endl;
#endif
  };
  int counter;
};

class VirtDer : public VirtBase {
public:
  void myFunc();
  virtual void virtFunc() {
    counter++;
#ifdef VERBOSE
    std::cout << "Called " << typeid(*this).name() << "::" << __func__
              << std::endl;
#endif
  };
  int counter;
};

int main(void) {
  PureBase pure;
  VirtBase vbase;
  VirtDer vder;
  PureBase *ppure = new PureBase();
  VirtBase *pvbase = new VirtBase();
  VirtDer *pvder = new VirtDer();
  VirtBase *pvbaseder = pvder;

  pure.myFunc();

  // MEASURETIME("test", 10, vbase.nvFunc();)
  vbase.nvFunc();
  vbase.virtFunc();

  vder.virtFunc();
  vder.nvFunc();
  vder.myFunc();

  ppure->myFunc();

  pvbase->nvFunc();
  pvbase->virtFunc();

  pvder->virtFunc();
  pvder->nvFunc();
  pvder->myFunc();

  pvbaseder->nvFunc();
  pvbaseder->virtFunc();
}
