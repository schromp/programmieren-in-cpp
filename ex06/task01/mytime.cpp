#include "mytime.hpp"
#include <iostream>

/**
 * @brief
 *
 * @param hour
 * @param minute
 * @param second
 */
MyTime::MyTime(const int hour, const int minute, const int second) {

  this->hour = 0;
  this->minute = 0;
  this->second = 0;

  int leftover_minutes = parseSecond(second);
  int leftover_hours = parseMinute(minute + leftover_minutes);
  this->hour = hour + leftover_hours;
}

/**
 * @brief parses input into correct values and writes them to minute in class
 *
 * @param input minutes
 *
 * @return leftover hours
 */
int MyTime::parseMinute(const int input) {
  if (input < 60) {
    this->minute = input;
    return 0;
  } else {
    int leftover_minutes = input % 60;
    int full_hours = input - leftover_minutes;
    int hours = full_hours / 60;

    this->minute = leftover_minutes;
    return hours;
  }
}

/**
 * @brief parses input into correct values and writes them to seconds in class
 *
 * @param input seconds
 *
 * @return leftover minutes
 */
int MyTime::parseSecond(const int input) {
  if (input < 60) {
    this->second = input;
    return 0;
  } else {
    int leftover_seconds = input % 60;
    int full_minutes = input - leftover_seconds;
    int minutes = full_minutes / 60;

    this->second += leftover_seconds;
    return minutes;
  }
}

/**
 * @brief get hour
 *
 * @return hour
 */
const int MyTime::getHour() { return this->hour; }

/**
 * @brief get minute
 *
 * @return minute
 */
const int MyTime::getMinute() { return this->minute; }

/**
 * @brief get second
 *
 * @return second
 */
const int MyTime::getSecond() { return this->second; }

/**
 * @brief int cast overload. returns the time in seconds
 *
 * @return time in seconds
 */
MyTime::operator int() const {

  int h_in_s = this->hour * 60 * 60;
  int m_in_s = this->minute * 60;
  return h_in_s + m_in_s + this->second;
}

/**
 * @brief overrides <<
 *
 * @param cout
 * @param time
 *
 * @return cout to be used further
 */
ostream &operator<<(ostream &cout, const MyTime &time) {
  printf("%02d:%02d:%02d", time.hour, time.minute, time.second);
  // cout << time.hour << ":" << time.minute << ":" << time.second;
  return cout;
}

/**
 * @brief overrides +
 *
 * @param time
 *
 * @return added time
 */
MyTime MyTime::operator+(const MyTime &time) {
  MyTime tm(this->hour + time.hour, this->minute + time.minute,
            this->second + time.second);
  return tm;
}

/**
 * @brief overrides + for time and integers
 *
 * @param seconds
 *
 * @return added time
 */
MyTime MyTime::operator+(const int &seconds) {
  MyTime tm(0, 0, seconds);
  return tm + *this;
}

MyTime operator+(const int seconds, const MyTime &time) {
  MyTime tm(0, 0, seconds);
  return tm + time;
}

MyTime& MyTime::operator +=(const MyTime& time) {
  *this = time + *this;
  return *this;
}

MyTime& MyTime::operator +=(const int& time) {
  *this = time + *this;
  return *this;
}
