#include <queue>
#include <string>


#include "EchoChatBot.hpp"

EchoChatBot::EchoChatBot(std::string name,
                         std::queue<std::string> &message_queue)
    : ChatBot(name, message_queue) {}

void EchoChatBot::on_message(std::string &message) {

  if (message.rfind("echo", 0) == 0 && message.find("?") != std::string::npos) {
    message.append("?");
    this->message_queue.push(message);
  }
}
