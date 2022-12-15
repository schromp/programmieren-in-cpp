#include "secarr.hpp"
#include <cstdio>

/**
 * @brief constructor
 *
 * @param start int of array
 * @param end int of array
 */
SecArr::SecArr(int *start, int *end) {
  if (start > end) {
    printf("Warning: start was after end");
    this->first = end;
    this->current = end;
    this->last = start;
  } else {
    this->first = start;
    this->current = start;
    this->last = end;
  }
}

/**
 * @brief dereferencing operator
 *
 * @return current accessed integer from array
 */
int &SecArr::operator*() { return *this->current; }

/**
 * @brief prefix increment operator. fails if out of bounds
 *
 * @return incremented SecArray
 */
SecArr& SecArr::operator++() {
  if(this->current == this->last) {
    printf("Invalid index\n");
  } else {
    this->current += 1;
  }
  return *this;
}

/**
 * @brief postfix increment operator. fails if out of bounds
 *
 * @param int
 *
 * @return temporary incremented SecArray
 */
SecArr SecArr::operator++(int) {
  SecArr temp = *this;
  if(this->current == this->last) {
    printf("Invalid index\n");
    return temp; 
  } else {
    this->current += 1;
    return temp;
  }
}

/**
 * @brief prefix decrement operator. fails if out of bounds
 *
 * @return decremented SecArray
 */
SecArr& SecArr::operator--() {
  if(this->current == this->first) {
    printf("Invalid index\n");
  } else {
    this->current -= 1;
  }
  return *this;
}

/**
 * @brief postfix decrement operator. fails if out of bounds
 *
 * @param int
 *
 * @return temporary decremented SecArray
 */
SecArr SecArr::operator--(int) {
  SecArr temp = *this;
  if(this->current == this->first) {
    printf("Invalid index\n");
    return temp;
  } else {
    this->current -= 1;
    return temp;
  }
}

/**
 * @brief [] access operator. fails if out of bounds
 *
 * @param index
 *
 * @return reference to int relative to position
 */
int& SecArr::operator[](int index) {
  if(first > (current + index)) {
    printf("Invalid index\n");
    return *first;
  } else if (last < (current + index)) {
    printf("Invalid index\n");
    return *last;
  } else {
    return *(current + index);
  }
}
