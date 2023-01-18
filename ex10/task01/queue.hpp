#ifndef LIST
#define LIST
#include "list.hpp"
#endif

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

template<typename T>
Queue<T>::Queue() {
  list = new List<T>();
}

template<typename T>
Queue<T>::~Queue() {
  delete list;
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const Queue<T> &queue) {
  os << *queue.list;
  return os;
}

template <typename T> void Queue<T>::add(T value) { list->add(value); }

template <typename T> T Queue<T>::remove() { return list->remove_front(); }

template <typename T> bool Queue<T>::isEmpty() const { return list->isEmpty(); }

template <typename T> bool Queue<T>::contains(T obj) {
  return list->contains(obj);
}

template <typename T> void Queue<T>::clear() { list->clear(); }

template <typename T> int Queue<T>::getSize() const { return list->getSize(); }



