#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


int main(int argc, char *argv[]){
  const std::string countodd ("countodd");
  const std::string hasnegative ("hasnegative");
  const std::string inc ("inc");
  const std::string sum ("sum");
  const std::string deleteodd ("deleteodd");

  if (argv[1] != nullptr) {
    std::vector<long> arguments(argv[2], argv[argc-1]);
    std::for_each(arguments.begin(), arguments.end(), [](long v){std::cout << v << " ";});
    std::cout << std::endl;
    if (countodd.compare(argv[1])) {
    } else if (hasnegative.compare(argv[1])) {
    } else if (inc.compare(argv[1])) {
    } else if (sum.compare(argv[1])) {
    } else if (deleteodd.compare(argv[1])) {
    }
  }
}
