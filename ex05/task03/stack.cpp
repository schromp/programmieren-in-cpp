#include "stack.hpp"
#include <cstdlib>
#include <iostream>
#include <string.h>

// CONSTRUCTOR and DESTRUCTOR

/**
 * @brief Default constructor. Allocates space for 10 integers
 */
Stack::Stack() {

  this->capacity_val = 10;
  this->length_val = 0;
  this->int_array = (int *)calloc(10, sizeof(int));
  std::cout << "Ctor: I am allocating space for 10 integers" << std::endl;
}

/**
 * @brief Constructor. Allocates space for i integers
 *
 * @param i amount of space that should be allocated
 */
Stack::Stack(int i) {

  this->capacity_val = i;
  this->length_val = 0;
  this->int_array = (int *)calloc(i, sizeof(int));
  // std::cout << "Ctor: I am allocating space for " << i << " integers"
  //           << std::endl;
}

/**
 * @brief copy constructor
 *
 * @param other the stack which should be copied
 */
Stack::Stack(const Stack &other)
    : capacity_val(other.capacity_val), length_val(other.length_val) {
  // std::cout << "Cctor called" << std::endl;
  this->int_array = (int *)calloc(capacity_val, sizeof(int));
  memcpy(this->int_array, other.int_array, sizeof(int) * capacity_val);
}

/**
 * @brief overloading Copy assignment operator
 *
 * @param other stack to be copied
 *
 * @return pointer to the copied stack
 */
Stack &Stack::operator=(const Stack &other) {
  // std::cout << "Cop= called" << std::endl;
  if (this != &other) {
    this->length_val = other.length_val;
    this->capacity_val = other.capacity_val;
    // this->int_array = (int *)calloc(capacity_val, sizeof(int));
    memcpy(this->int_array, other.int_array, sizeof(int) * capacity_val);
  }
  return *this;
}

/**
 * @brief Move constructor
 *
 * @param other the stack that will be moved
 */
Stack::Stack(Stack &&other)
    : capacity_val(other.capacity_val), length_val(other.length_val),
      int_array(other.int_array) {
  // std::cout << "Mctor called" << std::endl;
  other.int_array = NULL;
  other.capacity_val = 0;
  other.length_val = 0;
}

/**
 * @brief overloading move assignment operator
 *
 * @param other the stack that will be moved
 *
 * @return pointer to the new stack
 */
Stack &Stack::operator=(Stack &&other) {
  std::cout << "Mop= called" << std::endl;
  if (this != &other) {
    capacity_val = other.capacity_val;
    length_val = other.length_val;
    int_array = other.int_array;

    other.length_val = 0;
    other.capacity_val = 0;
    other.int_array = NULL;
  }
  return *this;
}

/**
 * @brief deconstructor
 */
Stack::~Stack() {
  // std::cout << "Dtor: I am deallocating a stack of " << capacity_val
  //           << " integers filled with " << length_val << " values."
  //           << std::endl;
  if (this->int_array != NULL) {
    free(this->int_array);
  }
}

/**
 * @brief if the stack is full
 *
 * @return stack is full or not
 */
bool Stack::is_full() { return capacity() == length(); }

/**
 * @brief if the stack is empty
 *
 * @return stack is empty or not
 */
bool Stack::is_empty() { return length() == 0; }

/**
 * @brief pushes an int onto the stack
 *
 * @param i the int that will be pushed
 */
void Stack::push(int i) {
  if (!is_full()) {
    int_array[length_val] = i;
    length_val++;
  } else {
    std::cout << "The stack is full" << std::endl;
  }
}

/**
 * @brief gives back the int on top of the stack and removes it
 *
 * @return the int on top of the stack or 0 if the stack is empty
 */
int Stack::pop() {
  if (!is_empty()) {
    int ret = int_array[length_val - 1];
    length_val--;
    return ret;
  } else {
    std::cout << "The stack is empty" << std::endl;
    return 0;
  }
}

/**
 * @brief prints the stack to the standard output
 */
void Stack::show() const {
  for (int i = 0; i < length_val; i++) {
    std::cout << int_array[i] << " ";
  }
  std::cout << std::endl;
}

/**
 * @brief get the capacity of the stack
 *
 * @return capacity of the stack
 */
int Stack::capacity() const { return this->capacity_val; }

/**
 * @brief get the amount of the currently stored values
 *
 * @return amount of the currently stored values
 */
int Stack::length() const { return this->length_val; }
