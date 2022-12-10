#include <ostream>

using std::ostream;

class MyTime {
public:
  MyTime(const int hour = 0, const int minute = 0, const int second = 0);
  operator int() const;
  friend ostream &operator<<(ostream &cout, const MyTime &time);
  MyTime operator+(const MyTime&);
  MyTime operator+(const int&);
  friend MyTime operator+(const int, const MyTime&);
  MyTime& operator +=(const MyTime&);
  MyTime& operator +=(const int&);

  const int getHour();
  const int getMinute();
  const int getSecond();

private:
  int hour;
  int minute;
  int second;

  int parseMinute(const int);
  int parseSecond(const int);
};
