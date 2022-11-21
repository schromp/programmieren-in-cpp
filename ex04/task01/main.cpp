#include <iostream>

/*
========  ADD YOUR CODE HERE ================
* Implement macro MAXM()
* Implement both maxf() functions
*/

/**
 * @brief calulates the bigger number
 *
 * @param a first number
 * @param b second number
 *
 * @return the bigger number
 */
#define MAXM(a, b) ((a > b) ? (a) : (b))

/**
 * @brief calulates the bigger int
 *
 * @param a first number
 * @param b second number
 *
 * @return the bigger number
 */
int maxf(int a, int b) {

  int aa = a;
  int bb = b;

  return MAXM(aa, bb);
}

/**
 * @brief calulates the bigger double
 *
 * @param a first number
 * @param b second number
 *
 * @return the bigger number
 */
double maxf(double a, double b) {

  double aa = a;
  double bb = b;

  return MAXM(aa, bb);
}

int main(void) {
  int a = 10, b = 20;
  std::cout << "MAXM1 = " << MAXM(a, b) << std::endl;
  std::cout << "MAXM2 = " << MAXM(a, b + 0.2) << std::endl;
  std::cout << "MAXM3 = " << MAXM(a, b++) << std::endl;
  std::cout << "maxf1 = " << maxf(a, b) << std::endl;
  // what's the problem with the following line?
  // std::cout << "maxf = " << maxf(a, b + 0.2) << std::endl;
  std::cout << "maxf2 = " << maxf(a + 0.1, b + 0.2) << std::endl;
  std::cout << "maxf3 = " << maxf(a, b++) << std::endl;
  std::cout << "a = " << a << ", b = " << b << std::endl;
}
