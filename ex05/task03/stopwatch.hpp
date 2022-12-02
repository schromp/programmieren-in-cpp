#include <bits/types/time_t.h>
#include <iostream>

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

class StopWatch {

  bool started;
  time_t start_time;
  time_t end_time;

public:
  StopWatch();

  void start();

  double stop();
};
