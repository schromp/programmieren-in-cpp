#include <algorithm>
#include <deque>
#include <iostream>
#include <iterator>
#include <list>
#include <utility>
#include <vector>

/**
 * @brief fills the container with the even values from 2 to 64
 *
 * @tparam Container the container type
 * @param cont the container to be filled
 */
template <typename Container> void fill(Container &cont) {
  for (int i = 2; i <= 64; i += 2) {
    cont.insert(cont.end(), i);
  }
}

/**
 * @brief prints all values of a container seperated by a space
 *
 * @tparam Container the container type
 * @param cont the container to be printed
 */
template <typename Container> void print(Container &cont) {
  typename Container::iterator it = cont.begin();
  for (; it != cont.end(); it++) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
}

/**
 * @brief print the next 3 elements after the iterator
 *
 * @tparam Container container type
 * @param cont container to be printed
 * @param it iterator from where shall be printed
 */
template <typename Container>
void printnext3(Container &cont, typename Container::iterator it) {
  typename Container::iterator threshold = it;
  std::advance(threshold, 3);
  for (typename Container::iterator iter = it; iter != threshold; ++iter) {
    if (iter == cont.end())
      break;
    std::cout << *iter << " ";
  }
  std::cout << std::endl;
}

/**
 * @brief find the point where to insert the value in the container while
 * staying sorted
 *
 * @tparam Container the container type
 * @param cont the container where to be searched
 * @param insert what should be inserted
 *
 * @return a pair of iterators, one before the insert, one on the insert
 */
template <typename Container>
std::pair<typename Container::iterator, typename Container::iterator>
findposition(Container &cont, typename Container::value_type &insert) {

  std::pair<typename Container::iterator, typename Container::iterator> pair;
  typename Container::iterator it = cont.begin();

  for (; it != cont.end(); it++) {
    if (*it > insert) {
#if !defined(FIX_A) && !defined(FIX_B)
      cont.insert(it, insert);
      pair.first = it;
      it++;
      pair.second = it;
      return pair;
#endif
#ifdef FIX_A
      cont.insert(it, insert);
      for (typename Container::iterator inner_it = cont.begin();
           inner_it != cont.end(); inner_it++) {
        if (*inner_it == insert) {
          pair.second = inner_it;
          inner_it--;
          pair.first = inner_it;
          return pair;
        }
      }
#endif
#ifdef FIX_B
      pair.second = cont.insert(it, insert);
      typename Container::iterator before = pair.second;
      before--;
      pair.first = before;
      return pair;
#endif
    }
  }

  return pair;
}

/**
 * @brief delete the odd values in the container
 *
 * @tparam Container
 * @param container
 */
template <typename Container> void deleteodd(Container &cont) {
  std::remove_if(cont.begin(), cont.end(), [](const typename Container::value_type& v) { return ((v % 2) == 1); });
}

/**
 * @brief Main method of the program
 *
 * @return status code
 */
int main(void) {

  std::vector<long> vector;
  std::deque<long> deque;
  std::list<long> list;

  fill(vector);
  fill(deque);
  fill(list);

  print(vector);
  print(deque);
  print(list);

  std::vector<long>::iterator vector_it = vector.begin();
  vector_it += 3;
  std::cout << *vector_it << std::endl;

  std::deque<long>::iterator deque_it = deque.begin();
  deque_it += 3;
  std::cout << *deque_it << std::endl;

  std::list<long>::iterator list_it = list.begin();
  list_it++;
  list_it++;
  list_it++;
  std::cout << *list_it << std::endl;

  long input = 31;
  std::pair<std::vector<long>::iterator, std::vector<long>::iterator>
      vector_pair = findposition(vector, input);
  printnext3(vector, vector_pair.first);

  std::pair<std::deque<long>::iterator, std::deque<long>::iterator> deque_pair =
      findposition(deque, input);
  printnext3(deque, deque_pair.first);

  std::pair<std::list<long>::iterator, std::list<long>::iterator> list_pair =
      findposition(list, input);
  printnext3(list, list_pair.first);

  print(vector);
  print(deque);
  print(list);

  deleteodd(vector);
  deleteodd(deque);
  deleteodd(list);

  print(vector);
  print(deque);
  print(list);

  return 0;
}
