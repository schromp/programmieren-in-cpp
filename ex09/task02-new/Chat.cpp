#include "Chat.hpp"
#include <iostream>
#include <ostream>

#include "EchoChatBot.hpp"

void Chat::parse_message(std::string message, std::string name) {
  if (name != "user") {
    std::cout << name << ":" << message << std::endl;
  } else {

    if (message.rfind("bot:") == 0) {
      std::string sub = message.substr(4);

      if (sub.rfind("echo,") == 0) {
        std::string new_name = sub.substr(6);
        EchoChatBot new_echo(new_name, this->message_queue);
        bots.push(new_echo);
        
      } else if (sub.rfind("quiz,") == 0) {
      }
      
    } else if (message == "exit") {
      running = false;
    }
  }
}
