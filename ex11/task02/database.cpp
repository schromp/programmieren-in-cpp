#include <iostream>
#include <map>
#include <string>
#include <vector>

int main(void) {

  std::map<std::string, std::vector<int>> database;
  std::string input;
  std::vector<std::string> input_buffer;

  while(input.compare(".")) {
    std::cin >> input;
    input_buffer.insert(input_buffer.end(), input);
  }

  return 0;
}
