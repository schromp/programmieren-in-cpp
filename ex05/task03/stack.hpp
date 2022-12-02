
class Stack {

private:
  int *int_array;
  int length_val;
  int capacity_val;

public:
  Stack(); // default 10
  Stack(int);

  // Copy constructor
  Stack(const Stack &);

  // Copy assignment operator
  Stack &operator=(const Stack &); // const may be missing aswell

  // Move constructor
  Stack(Stack &&);

  // Move assignment operator
  Stack &operator=(Stack &&);

  ~Stack(); // deallocate memory

  bool is_full();
  bool is_empty();

  void push(int);
  int pop();

  void show() const;
  int capacity() const;
  int length() const;
};
