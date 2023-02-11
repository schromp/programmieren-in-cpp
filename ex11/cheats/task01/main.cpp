#include <vector>
#include <deque>
#include <list>

#include "containers.cpp"

#ifdef DEBUG
#define TEST(n) std::cout << "--- TESTING " << n << " ---" << std::endl
#endif

/**
   @brief Function to test my implementation of containeres.cpp

   @result 0 if program ran successfully. (is done by g++)
*/
int main(int argc, char** argv) {
#ifdef DEBUG
  TEST("Initialize a vector, a deque and a list of \"long\" values.");
#endif
  std::vector<long> vec;
  std::deque<long> deq;
  std::list<long> lst;

#ifdef DEBUG
  TEST("Fill them using the previously defined fill-function");
#endif
  fill(vec);
  fill(deq);
  fill(lst);

#ifdef DEBUG
  TEST("Define an iterator for each container ");
#endif
  std::vector<long>::iterator vec_it;
  std::deque<long>::iterator deq_it;
  std::list<long>::iterator lst_it;

#ifdef DEBUG
  TEST("set it to the first element");
#endif
  vec_it = vec.begin();
  deq_it = deq.begin();
  lst_it = lst.begin();

#ifdef DEBUG
  TEST("Advance the iterator to the third element using as few arithmetic operations as possible.");
#endif
  std::advance(vec_it, 2);
  std::advance(deq_it, 2);
  std::advance(lst_it, 2);

#ifdef DEBUG
  TEST("Print out the element the iterator now points to.");
#endif
  std::cout << *vec_it << std::endl;
  std::cout << *deq_it << std::endl;
  std::cout << *lst_it << std::endl;

#ifdef DEBUG
  TEST("Use findposition() to find a position for 31 in each container and insert it there.");
#endif
  std::pair<typename std::vector<long>::const_iterator,typename std::vector<long>::const_iterator> find_pos_vec = findposition(vec,31);
  std::pair<typename std::deque<long>::const_iterator,typename std::deque<long>::const_iterator> find_pos_deq = findposition(deq, 31);
  std::pair<typename std::list<long>::const_iterator,typename std::list<long>::const_iterator> find_pos_lst = findposition(lst, 31);

#ifdef DEBUG
  TEST("Then call printnext3() starting at the element before the insert position.");
#endif
  printnext3(vec, find_pos_vec.first);
  std::cout << std::endl;
  printnext3(deq, find_pos_deq.first);
  std::cout << std::endl;
  printnext3(lst, find_pos_lst.first);
  std::cout << std::endl;

#ifdef DEBUG
  TEST("Print out all three containers using print().");
#endif
  print(vec);
  std::cout << std::endl;
  print(deq);
  std::cout << std::endl;
  print(lst);
  std::cout << std::endl;

#ifdef DEBUG
  TEST("Delete all odd values in each container");
#endif
  deleteodd(vec);
  deleteodd(deq);
  deleteodd(lst);

#ifdef DEBUG
  TEST("print() them out again.");
#endif
  print(vec);
  std::cout << std::endl;
  print(deq);
  std::cout << std::endl;
  print(lst);
  std::cout << std::endl;
}

