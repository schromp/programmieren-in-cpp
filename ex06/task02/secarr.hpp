class SecArr {
private:
  int *current;
  int *first;
  int *last;

public:
  SecArr(int*, int*);
  int& operator*();
  SecArr& operator++(); //++a
  SecArr operator++(int); //a++
  SecArr& operator--(); //--a
  SecArr operator--(int); //a--
  int& operator[](int);
};
