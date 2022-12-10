#include <iostream>
#include <stdio.h>
#include <string.h>

using std::ostream;

/**
 * @brief overloads the << operator to print ---start--- and ---end---
 *
 * @param cout the cout before the <<
 * @param string the string after the <<
 *
 * @return cout so it can be further used
 */
ostream &operator<<(ostream &cout, const char *string) {

  int string_length = strlen(string);
  
  char start[13] = "---start---\n";
  for (int i = 0; i < strlen(start); i++) {
    printf("%c", start[i]);
  }

  for(int i = 0; i < string_length; i++) {
    printf("%c", string[i]);
  }
  
  printf("\n");

  char end[10] = "---end---";
  for (int i = 0; i < strlen(end); i++) {
    printf("%c", end[i]);
  }

  return cout;
}

int main(void) {
  std::cout << "Hello world!" << std::endl;
  return 0;
}
