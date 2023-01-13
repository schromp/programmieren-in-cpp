#include <iostream>
#include <queue>
#include <string>

#include "EchoChatBot.hpp"
#include "Chat.hpp"

void parse_message(std::string message, std::string name);
void shutdown();


int main(void) {
  Chat chat;
  std::string user_message;

  while (chat.is_running()) {
    std::cin >> user_message;
    parse_message(user_message, "user");
  }
  chat.shutdown();
}

