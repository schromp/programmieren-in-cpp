#include <iostream>
#include <string>

#include "include/Chat.hpp"

int main(void) {

  Chat chat;

  std::string user_message;
  bool isRunning = true;

  while (isRunning) {
    std::cin >> user_message;
    chat.sendMessage(user_message, "user");
  }
}
