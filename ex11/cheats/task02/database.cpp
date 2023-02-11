#include <iostream>
#include <string>
#include <vector>
#include <map>

typedef std::string key;
typedef std::vector<int> value;

/**
   @brief 

   @result 
*/
int main(int argc, char *argv[]){
  std::map<key,value> db;
  std::string input;
  std::vector<std::string> input_buffer;

  while (input.compare(".")) {
    std::cin >> input;
    input_buffer.insert(input_buffer.end(), input);
  }
}
