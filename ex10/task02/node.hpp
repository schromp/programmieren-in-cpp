template <typename T> class Node {
public:
  T content;
  Node *next;
  Node *previous;

  Node(T content, Node *next, Node *previous);
  ~Node();
};

template <typename T>
Node<T>::Node(T content, Node *next, Node *previous)
    : content(content), next(next), previous(previous) {}

template <typename T> Node<T>::~Node<T>() {
  next = nullptr;
  previous = nullptr;
}
