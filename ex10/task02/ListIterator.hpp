#ifndef NODE
#define NODE
#include "node.hpp"
#endif
#include <iterator>

template <typename T>
class ListIterator : public std::iterator<std::random_access_iterator_tag, T> {
  Node<T> *node;

public:
  ListIterator<T>(Node<T> *node);
  ~ListIterator<T>();

  bool operator==(const ListIterator<T> &i);
  bool operator!=(const ListIterator<T> &i);
  T operator*();
  ListIterator<T> &operator++();
  ListIterator<T> &operator--();
};

/**
 * @brief create iterator on given node
 *
 * @tparam T
 * @param node
 */
template <typename T>
ListIterator<T>::ListIterator(Node<T> *node) : node(node) {}

/**
 * @brief destructor
 *
 * @tparam T
 */
template <typename T> ListIterator<T>::~ListIterator() {}

/**
 * @brief check if iterator is equal to other iterator
 *
 * @tparam T
 * @param i
 *
 * @return 
 */
template <typename T>
bool ListIterator<T>::operator==(const ListIterator<T> &i) {
  return (this->node == i.node);
}

/**
 * @brief check if iterator is unequal to other iterator
 *
 * @tparam T
 * @param i
 *
 * @return 
 */
template <typename T>
bool ListIterator<T>::operator!=(const ListIterator<T> &i) {
  return (this->node != i.node);
}

/**
 * @brief get value from iterator
 *
 * @tparam T
 *
 * @return 
 */
template <typename T> T ListIterator<T>::operator*() { return node->content; }

/**
 * @brief put iterator 1 position forwards
 *
 * @tparam T
 *
 * @return 
 */
template <typename T> ListIterator<T> &ListIterator<T>::operator++() {
  if (node->next != NULL) {
    node = node->next;
  }
  return this;
}

/**
 * @brief put iterator 1 position backwards
 *
 * @tparam T
 *
 * @return 
 */
template <typename T> ListIterator<T> &ListIterator<T>::operator--() {
  if (node->previous != NULL) {
    node = node->previous;
  }
  return this;
}
