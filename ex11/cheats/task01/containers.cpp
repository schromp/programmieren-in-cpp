#ifndef _CONTAINERS_CPP
#define _CONTAINERS_CPP
#include <algorithm>
#include <iostream>

/**
   @brief Fills a container with all even numbers from 2 to 64

   @param[in] container Container that will be filled.
*/
template <typename Container> void fill(Container &container);

/**
   @brief Prints the content of the container seperated by spaces

   @param[in] container Container that will be printed.
*/
template <typename Container> void print(Container &container);

/**
   @brief Prints out three elements starting from the iterator.

   @param[in] container Container to print from
   @param[in] it Iterator to start printing from.
*/
template <typename Container>
void printnext3(Container &container, typename Container::const_iterator it);

/**
   @brief Insert the given value into the order of the container.

   Inserts the given value into the container, so that the numbers are still in
   ascending order.

   @param[in] container Container to add value to.
   @param[in] value Value to insert into the container.
   @result Pair of the iterator before the inserted value and the iterator of
   the inserted value
*/
template <typename Container>
std::pair<typename Container::const_iterator,
          typename Container::const_iterator>
findposition(Container &container, typename Container::value_type &value);

/**
   @brief Remove all odd numbers from the container

   @param[in] container Container to remove odd numbers from.
*/
template <typename Container> void deleteodd(Container &container);

template <typename Container> void fill(Container &container) {
  std::remove_if(container.begin(), container.end(),
                 [](const typename Container::value_type &) { return true; });
  for (int i = 2; i <= 64; i += 2) {
    container.insert(container.end(), i);
  }
}

template <typename Container> void print(Container &container) {
  for (typename Container::const_iterator it = container.begin();
       it != container.end(); ++it) {
    std::cout << *it << " ";
  }
}

template <typename Container>
void printnext3(Container &container, typename Container::const_iterator it) {
  typename Container::const_iterator it_threshold = it;
  std::advance(it_threshold, 3);
  for (typename Container::const_iterator cit = it; cit != it_threshold;
       ++cit) {
    if (cit == container.end()) {
      break;
    }
    std::cout << *cit << " ";
  }
}

template <typename Container>
std::pair<typename Container::const_iterator,
          typename Container::const_iterator>
findposition(Container &container,
             const typename Container::value_type &value) {
  typename Container::const_iterator res_first;
  typename Container::const_iterator res_second;
  for (typename Container::iterator it = container.begin();
       it != container.end(); ++it) {
    if (*it > value) {
      res_second = container.insert(it, value);
      res_first = res_second;
      std::advance(res_first, -1);
      break;
    }
  }
  return std::pair<typename Container::const_iterator,
                   typename Container::const_iterator>(res_first, res_second);
}

template <typename Container> void deleteodd(Container &container) {
  container.erase(std::remove_if(container.begin(), container.end(),
                                 [](const typename Container::value_type &val) {
                                   return (val % 2) == 1;
                                 }),
                  container.end());
}
#endif
