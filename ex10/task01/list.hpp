#define LIST
#ifndef COLLECTION
#define COLLECTION
#include "collection.hpp"
#endif

#ifndef NODE
#define NODE
#include "node.hpp"
#endif

#include <ostream>

template <typename T> class List;

template <typename T>
std::ostream &operator<<(std::ostream &out, const List<T> &list);

template <typename T> class List : public Collection<T> {
private:
  Node<T> *first;
  Node<T> *last;

public:
  List();
  ~List();

  template <typename U>
  friend std::ostream &operator<<(std::ostream &os, const List<U> &list);

  void add_front(T value);
  void add(T value);
  T remove_front();
  T remove();
  bool isEmpty() const;
  bool contains(T obj);
  int getSize() const;
  void clear();
  Node<T> *getFirst() const;
  Node<T> *getLast() const;
};

template <typename T> List<T>::List() {
  this->first = nullptr;
  this->last = nullptr;
}

template <typename T> List<T>::~List() {
  if (!isEmpty()) {
    Node<T> *current = first;
    while (current->next != nullptr) {
      Node<T> *del = current;
      current = current->next;
      delete del;
    }
  }
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const List<T> &list) {
  if (list.isEmpty()) {
    return os;
  } else {
    Node<T> *current = list.getFirst();
    os << current->content << " ";
    while (current->next != nullptr) {
      current = current->next;
      os << current->content << " ";
    }
    os << std::endl;
    return os;
  }
}

template <typename T> void List<T>::add(T value) {
  if (isEmpty()) {
    Node<T> *node = new Node<T>(value, nullptr, nullptr);
    first = node;
    last = node;
  } else {
    Node<T> *node = new Node<T>(value, nullptr, last);
    last->next = node;
    last = node;
  }
}

template <typename T> void List<T>::add_front(T value) {
  if (isEmpty()) {
    Node<T> *node = new Node<T>(value, nullptr, nullptr);
    first = node;
    last = node;
  } else {
    Node<T> *node = new Node<T>(value, first, nullptr);
    first->previous = node;
    first = node;
  }
}

template <typename T> T List<T>::remove() {
  if (isEmpty()) {
    return 0;
  } else if (first == last) {
    Node<T> *save = last;
    first = nullptr;
    last = nullptr;
    return save->content;
  } else {
    Node<T> *save = last;
    last = last->previous;
    last->next = nullptr;
    return save->content;
  }
}

template <typename T> T List<T>::remove_front() {
  if (isEmpty()) {
    return 0;
  } else if (first == last) {
    Node<T> *save = first;
    first = nullptr;
    last = nullptr;
    return save->content;
  } else {
    Node<T> *save = first;
    first = first->next;
    first->previous = nullptr;
    return save->content;
  }
}

template <typename T> bool List<T>::isEmpty() const {
  if (first == nullptr && last == nullptr) {
    return true;
  } else {
    return false;
  }
}

template <typename T> bool List<T>::contains(T obj) {
  if (!isEmpty()) {
    Node<T> *current = first;
    if (current->content == obj)
      return true;
    while (current->next != nullptr) {
      current = current->next;
      if (current->content == obj)
        return true;
    }
  }
  return false;
}

template <typename T> void List<T>::clear() {
  first = nullptr;
  last = nullptr;
}

template <typename T> int List<T>::getSize() const {
  if (isEmpty()) {
    return 0;
  } else if (first == last) {
    return 1;
  } else {
    Node<T> *current = first;
    int size = 0;
    while (current->next != nullptr) {
      current = current->next;
      size++;
    }
    return size;
  }
}

template <typename T> Node<T> *List<T>::getFirst() const { return this->first; }

template <typename T> Node<T> *List<T>::getLast() const { return last; }
