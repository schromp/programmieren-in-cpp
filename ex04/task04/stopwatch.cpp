#include <ctime>
#include <iostream>
#include <ostream>
#include <time.h>


/**
* @brief Class that implements a stopwatch with the methods start and stop
*/
class StopWatch {

  bool started = false;
  time_t start_time;
  time_t end_time;

public:
  /**
   * @brief starts the stopwatch if not started yet otherwise print an error
   */
  void start() {
    if (!started) {
      started = true;
      // clock(&start_time);
      start_time = clock();
    } else {
      std::cout << "StopWatch already running!" << std::endl;
    }
  }

  /**
   * @brief stops the time of the stopwatch
   *
   * @return 0 if the clock wasnt started yet and the time difference if the
   * clock was started
   */
  double stop() {
    if (started) {
      end_time = clock() ;
      return difftime(end_time, start_time) / CLOCKS_PER_SEC;
    } else {
      std::cout << "StopWatch not started yet!" << std::endl;
      return 0;
    }
  }
};
