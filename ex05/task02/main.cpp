#include <ostream>
#include <stdio.h>

namespace std {
struct dummy {};

dummy cout;
// dummy endl;

dummy &operator<<(dummy &d, const dummy &other) {
  printf("---start---");
  printf("\n-\n");
  return d;
}

ostream &operator<<(ostream &os, const char &toPrint) {
  return os << printf("---start---");
};

} // namespace std

int main(void) {
  std::cout << "Hello world !" << std::endl;
  return 0;
}
