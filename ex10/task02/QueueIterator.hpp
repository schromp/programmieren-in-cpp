#ifndef NODE
#define NODE
#include "node.hpp"
#endif
#include <iterator>

template <typename T>
class QueueIterator : public std::iterator<std::random_access_iterator_tag, T> {
  Node<T> *node;

public:
  QueueIterator<T>(Node<T> *node);
  ~QueueIterator<T>();

  bool operator==(const QueueIterator<T> &i);
  bool operator!=(const QueueIterator<T> &i);
  T operator*();
  QueueIterator<T> &operator++();
};

/**
 * @brief create iterator on given node
 *
 * @tparam T
 * @param node
 */
template <typename T>
QueueIterator<T>::QueueIterator(Node<T> *node) : node(node) {}

/**
 * @brief destructor
 *
 * @tparam T
 */
template <typename T> QueueIterator<T>::~QueueIterator() {}

/**
 * @brief check if iterator is equal to other iterator
 *
 * @tparam T
 * @param i
 *
 * @return 
 */
template <typename T>
bool QueueIterator<T>::operator==(const QueueIterator<T> &i) {
  return (this->node == i.node);
}

/**
 * @brief check if iterator is notequal to other iterator
 *
 * @tparam T
 * @param i
 *
 * @return 
 */
template <typename T>
bool QueueIterator<T>::operator!=(const QueueIterator<T> &i) {
  return (this->node != i.node);
}

/**
 * @brief get value from iterator
 *
 * @tparam T
 *
 * @return value
 */
template <typename T> T QueueIterator<T>::operator*() { return node->content; }

/**
 * @brief put iterator 1 element further in queue
 *
 * @tparam T
 *
 * @return 
 */
template <typename T> QueueIterator<T> &QueueIterator<T>::operator++() {
  if (node->next != NULL) {
    node = node->next;
  }
  return this;
}
