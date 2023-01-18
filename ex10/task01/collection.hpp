template<typename T>
class Collection {
public:
  virtual void add(T value) = 0;
  virtual T remove() = 0;
  virtual bool isEmpty() const = 0;
  virtual bool contains(T obj) = 0;
  virtual void clear() = 0;
  virtual int getSize() const = 0;
};
