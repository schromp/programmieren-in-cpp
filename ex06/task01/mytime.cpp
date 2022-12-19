#include "mytime.hpp"
#include <iostream>

MyTime::MyTime(const int hour, const int minute, const int second) {

  this->hour = 0;
  this->minute = 0;
  this->second = 0;

  int leftover_minutes = parseSecond(second);
  int leftover_hours = parseMinute(minute + leftover_minutes);
  this->hour = hour + leftover_hours;
}

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

const int MyTime::getHour() const { return this->hour; }

const int MyTime::getMinute() const { return this->minute; }

const int MyTime::getSecond() const { return this->second; }

MyTime::operator int() const {
  int h_in_s = this->hour * 60 * 60;
  int m_in_s = this->minute * 60;
  return h_in_s + m_in_s + this->second;
}

ostream &operator<<(ostream &cout, const MyTime &time) {
  printf("%02d:%02d:%02d", time.hour, time.minute, time.second);
  // cout << time.hour << ":" << time.minute << ":" << time.second;
  return cout;
}

MyTime MyTime::operator+(const MyTime &time) {
  MyTime tm(this->hour + time.hour, this->minute + time.minute,
            this->second + time.second);
  return tm;
}

MyTime MyTime::operator+(const int &seconds) {
  MyTime tm(0, 0, seconds);
  return tm + *this;
}

MyTime operator+(const int seconds, const MyTime &time) {
  MyTime tm(0, 0, seconds);
  return tm + time;
}

MyTime &MyTime::operator+=(const MyTime &time) {
  *this = time + *this;
  return *this;
}

MyTime &MyTime::operator+=(const int &time) {
  *this = time + *this;
  return *this;
}
