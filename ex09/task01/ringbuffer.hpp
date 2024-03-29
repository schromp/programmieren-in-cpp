#include <iostream>
#include <stdexcept>

template <typename T, int NUM> class RingBuffer {
private:
  T queue[NUM];
  int size;
  int front_index;
  int back_index;

public:
  RingBuffer();
  void push_front(T);
  T pop_front();

  void push_back(T);
  T pop_back();

  bool empty();
  bool full();
  void print();
};

/**
 * @brief constructor
 *
 * @tparam T type to be stored in ring
 * @tparam NUM size of the ring
 */
template <typename T, int NUM> RingBuffer<T, NUM>::RingBuffer() {
  this->size = 0;
  this->front_index = 0;
  this->back_index = 0;
}

/**
 * @brief push value at front of ring
 *
 * @tparam T stored type in ring
 * @tparam NUM size of ring
 * @param insert value to be inserted
 */
template <typename T, int NUM> void RingBuffer<T, NUM>::push_front(T insert) {

  if (full()) {
    return;
  } else if (empty()) {
    this->queue[front_index] = insert;
    this->size++;
  } else {
    if (front_index == 0) {
      this->front_index = NUM-1;
    } else {
      this->front_index -= 1;
    }
    this->queue[this->front_index] = insert;
    this->size++;
  }
}

/**
 * @brief pop value from front of ring
 *
 * @tparam T stored type in ring
 * @tparam NUM size of ring
 *
 * @return popped value
 */
template <typename T, int NUM> T RingBuffer<T, NUM>::pop_front() {
  if (empty()) {
    throw std::out_of_range("pop_front on empty buffer\n");
  } else if (size == 1) {
    T removed = this->queue[this->front_index];
    this->size--;
    return removed;
  } else {
    T removed = this->queue[this->front_index];

    if (this->front_index == NUM - 1) {
      this->front_index = 0;
    } else {
      this->front_index += 1;
    }
    this->size--;

    return removed;
  }
}

/**
 * @brief push value to the back of ring
 *
 * @tparam T type to be stored inside ring
 * @tparam NUM size of ring
 * @param insert value to be inserted
 */
template <typename T, int NUM> void RingBuffer<T, NUM>::push_back(T insert) {

  if (full()) {
    return;
  } else if (empty()) {
    this->queue[this->back_index] = insert;
    this->size++;
  } else {
    if (this->back_index == NUM - 1) {
      back_index = 0;
    } else {
      this->back_index += 1;
    }
    this->queue[this->back_index] = insert;
    this->size++;
  }
}

/**
 * @brief pop value from back of ring
 *
 * @tparam T type to be stored inside ring
 * @tparam NUM size of ring
 *
 * @return popped value
 */
template <typename T, int NUM> T RingBuffer<T, NUM>::pop_back() {

  if (empty()) {
    throw std::out_of_range("pop_back on empty buffer\n");
  } else if (this->size == 1) {
    T removed = this->queue[this->back_index];
    this->size--;

    return removed;
  } else {
    T removed = this->queue[this->back_index];
    if (this->back_index == 0) {
      back_index = size - 1;
    } else {
      this->back_index -= 1;
    }
    this->size--;

    return removed;
  }
}

/**
 * @brief check if ring empty
 *
 * @tparam T stored type of ring
 * @tparam NUM size of ring
 *
 * @return is empty?
 */
template <typename T, int NUM> bool RingBuffer<T, NUM>::empty() {
  return this->size == 0 ? true : false;
}

/**
 * @brief check if ring full
 *
 * @tparam T stored type of ring
 * @tparam NUM size of ring
 *
 * @return is full?
 */
template <typename T, int NUM> bool RingBuffer<T, NUM>::full() {
  return this->size == NUM ? true : false;
}

/**
 * @brief print current ring
 *
 * @tparam T stored type of ring
 * @tparam NUM size of ring
 */
template <typename T, int NUM> void RingBuffer<T, NUM>::print() {
  if (empty()) {
    std::cout << "Buffer is empty" << std::endl;
  } else {
    int current = this->front_index;
    std::cout << this->queue[current] << "\t";

    while (current != this->back_index) {
      if (current == NUM-1) {
        current = 0;
      } else {
        current++;
      }
      std::cout << this->queue[current] << "\t";
    }
    std::cout << std::endl;
  }
}
