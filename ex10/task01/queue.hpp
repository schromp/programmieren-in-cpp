#ifndef LIST
#define LIST
#include "list.hpp"
#endif

/**
 * @brief queue implementation which adds to back and removes from front
 *
 * @tparam T type to be stored in list
 */
template <typename T> class Queue : public Collection<T> {
  List<T> *list;

public:
  Queue();
  ~Queue();

  template <typename U>
  friend std::ostream &operator<<(std::ostream &os, const Queue<U> &queue);

  void add(T value);
  T remove();
  bool isEmpty() const;
  bool contains(T obj);
  void clear();
  int getSize() const;

};

/**
 * @brief constructor - puts a new list into memory
 *
 * @tparam T
 */
template<typename T>
Queue<T>::Queue() {
  list = new List<T>();
}

/**
 * @brief destructor - deletes list from memory
 *
 * @tparam T
 */
template<typename T>
Queue<T>::~Queue() {
  delete list;
}

/**
 * @brief overloading << for cout
 *
 * @tparam T
 * @param os cout
 * @param queue queue to be outputted
 *
 * @return cout to be used further
 */
template <typename T>
std::ostream &operator<<(std::ostream &os, const Queue<T> &queue) {
  os << *queue.list;
  return os;
}

/**
 * @brief add a value at the end of the queue
 *
 * @tparam T
 * @param value to be added
 */
template <typename T> void Queue<T>::add(T value) { list->add(value); }

/**
 * @brief remove the value at the start of the queue
 *
 * @tparam T
 *
 * @return the removed value
 */
template <typename T> T Queue<T>::remove() { return list->remove_front(); }

/**
 * @brief check if queue is empty
 *
 * @tparam T
 *
 * @return bool queue is empty
 */
template <typename T> bool Queue<T>::isEmpty() const { return list->isEmpty(); }

/**
 * @brief check if queue contains value
 *
 * @tparam T
 * @param obj
 *
 * @return bool does contain value
 */
template <typename T> bool Queue<T>::contains(T obj) {
  return list->contains(obj);
}

/**
 * @brief clear the queue
 *
 * @tparam T
 */
template <typename T> void Queue<T>::clear() { list->clear(); }

/**
 * @brief get the size of the queue
 *
 * @tparam T
 *
 * @return size of the queue
 */
template <typename T> int Queue<T>::getSize() const { return list->getSize(); }



