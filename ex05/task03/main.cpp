#include "stack.hpp"
#include "stopwatch.hpp"
#include <iostream>


Stack random_stack() {
  Stack s1(10000);
  for (int i = 0; i < 10000; i++) {
    s1.push(rand());
  }
  return s1;
}

Stack test(Stack stack) { return stack; }

int main() {

  Stack s1 = random_stack();

  MEASURETIME("Copy assignment test", 100000, Stack s2 = s1; Stack s3(10000); s3 = s2;) 
  MEASURETIME("Move assignment test", 100000, Stack s2 = s1; Stack s3(s2);)

  return 0;
}
