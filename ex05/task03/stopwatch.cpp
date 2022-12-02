#include "stopwatch.hpp"
#include <ctime>
#include <iostream>
#include <ostream>
#include <time.h>



/**
 * @brief constructor
 */
StopWatch::StopWatch() : started(false){};

/**
 * @brief starts the stopwatch if not started yet otherwise print an error
 */
void StopWatch::start() {
  if (!started) {
    started = true;
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
double StopWatch::stop() {
  if (started) {
    end_time = clock();
    return difftime(end_time, start_time) / CLOCKS_PER_SEC;
  } else {
    std::cout << "StopWatch not started yet!" << std::endl;
    return 0;
  }
}
