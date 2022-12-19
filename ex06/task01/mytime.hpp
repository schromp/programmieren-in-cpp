#include <ostream>

using std::ostream;

class MyTime {
public:
  /**
   * @brief constructor
   *
   * @param hour
   * @param minute
   * @param second
   */
  MyTime(const int hour = 0, const int minute = 0, const int second = 0);

  /**
   * @brief int cast overload returns time in seconds
   *
   * @return
   */
  operator int() const;

  /**
   * @brief overloads <<
   *
   * @param cout
   * @param time
   *
   * @return cout to be used further
   */
  friend ostream &operator<<(ostream &cout, const MyTime &time);

  /**
   * @brief overloads +
   *
   * @param MyTime
   *
   * @return
   */
  MyTime operator+(const MyTime &);

  /**
   * @brief overloads + for the combination mytime + int
   *
   * @param int
   *
   * @return new time object
   */
  MyTime operator+(const int &);

  /**
   * @brief
   *
   * @param int
   * @param MyTime
   *
   * @return
   */
  friend MyTime operator+(const int, const MyTime &);

  /**
   * @brief overrides += for Mytime
   *
   * @param MyTime
   *
   * @return mytime
   */
  MyTime &operator+=(const MyTime &);

  /**
   * @brief overrides += for mytime and int
   *
   * @param int
   *
   * @return new mytime
   */
  MyTime &operator+=(const int &);

  /**
   * @brief get the hour of time
   *
   * @return hour
   */
  const int getHour() const;

  /**
   * @brief get minute of time
   *
   * @return minute
   */
  const int getMinute() const;

  /**
   * @brief get seconds of time
   *
   * @return second
   */
  const int getSecond() const;

private:
  int hour;
  int minute;
  int second;

  /**
   * @brief parse Minute into Hours and Minutes
   *
   * @param int
   *
   * @return rest hours
   */
  int parseMinute(const int);

  /**
   * @brief parse Seconds into Minutes and Seconds
   *
   * @param int
   *
   * @return rest minutes
   */
  int parseSecond(const int);
};
