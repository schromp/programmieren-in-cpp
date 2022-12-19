#include "stopwatch.hpp"

/**
 * @brief measures time for the given instruction
 *
 * @param description
 * @param repetitions
 * @param instructions2test
 */
#define MEASURETIME(description, repetitions, instructions2test)               \
  {                                                                            \
    StopWatch sw;                                                              \
    sw.start();                                                                \
    for (int i = 0; i < repetitions; i++) {                                    \
      instructions2test                                                        \
    }                                                                          \
    double stop = sw.stop();                                                   \
    std::cout << "My computer requires " << stop << " seconds to execute "     \
              << description << " " << repetitions << " times" << std::endl;   \
  }

class StaticBase {
  static int counter;

public:
  StaticBase() { counter = 0; };
  static void myFunc() {
    counter++;
#ifdef VERBOSE
    std::cout << "Called StaticBase::" << __func__ << std::endl;
#endif
  };
};

class PureBase {
private:
  int counter;

public:
  PureBase() { counter = 0; };
  void myFunc() {
    counter++;
#ifdef VERBOSE
    std::cout << "Called " << typeid(*this).name() << "::" << __func__
              << std::endl;
#endif
  };
};

class VirtBase {
  int counter;

public:
  VirtBase() { counter = 0; };
  virtual void nvFunc() {
    counter++;
#ifdef VERBOSE
    std::cout << "Called " << typeid(*this).name() << "::" << __func__
              << std::endl;
#endif
  };
  virtual void virtFunc() {
    counter++;
#ifdef VERBOSE
    std::cout << "Called " << typeid(*this).name() << "::" << __func__
              << std::endl;
#endif
  };
};

class VirtDer : public VirtBase {
  int counter;

public:
  void myFunc() { counter = 0; };
  virtual void virtFunc() {
    counter++;
#ifdef VERBOSE
    std::cout << "Called " << typeid(*this).name() << "::" << __func__
              << std::endl;
#endif
  };
};

int main(void) {
  PureBase pure;
  VirtBase vbase;
  VirtDer vder;
  PureBase *ppure = new PureBase();
  VirtBase *pvbase = new VirtBase();
  VirtDer *pvder = new VirtDer();
  VirtBase *pvbaseder = pvder;

  // StaticBase::myFunc();

  // Invokes from same class and pure function
  pure.myFunc();
  vder.myFunc();
  ppure->myFunc();
  pvder->myFunc();

  // Invokes from same class and virtual function
  vder.virtFunc();
  pvder->virtFunc();
  vbase.nvFunc();
  vbase.virtFunc();
  pvbase->nvFunc();
  pvbase->virtFunc();

  // Invokes from base class and virtual function
  vder.nvFunc();
  pvder->nvFunc();
  pvbaseder->nvFunc();
  pvbaseder->virtFunc();

#ifdef TASK02
  // MEASURETIME("StaticBase::myFunc()", 50000000, StaticBase::myFunc();)

  // Invokes from same class and pure function
  MEASURETIME("pure.myFunc()", 50000000, pure.myFunc();)
  MEASURETIME("vder.myFunc()", 50000000, vder.myFunc();)
  MEASURETIME("ppure->myFunc()", 50000000, ppure->myFunc();)
  MEASURETIME("pvder->myFunc()", 50000000, pvder->myFunc();)

  // Invokes from same class and virtual function
  MEASURETIME("vder.virtFunc()", 50000000, vder.virtFunc();)
  MEASURETIME("pvder->virtFunc()", 50000000, pvder->virtFunc();)
  MEASURETIME("vbase.nvFunc()", 50000000, vbase.nvFunc();)
  MEASURETIME("vbase.virtFunc()", 50000000, vbase.virtFunc();)
  MEASURETIME("pvbase->nvFunc()", 50000000, pvbase->nvFunc();)
  MEASURETIME("pvbase->virtFunc()", 50000000, pvbase->virtFunc();)

  // Invokes from base class and virtual function
  MEASURETIME("vder.nvFunc()", 50000000, vder.nvFunc();)
  MEASURETIME("pvder->nvFunc()", 50000000, pvder->nvFunc();)
  MEASURETIME("pvbaseder->nvFunc()", 50000000, pvbaseder->nvFunc();)
  MEASURETIME("pvbaseder->virtFunc()", 50000000, pvbaseder->virtFunc();)
#endif

#ifdef TASK03

  VirtDer *pvbasestcast = static_cast<VirtDer *>(pvbase);
  MEASURETIME("static", 50000000, pvbasestcast->myFunc();)
  VirtDer *pvbasedyncast = dynamic_cast<VirtDer *>(pvder);
  MEASURETIME("dynamic", 50000000, pvbasedyncast->myFunc();)

#endif
}
