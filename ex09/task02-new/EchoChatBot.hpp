#include <string>
#ifndef CHATBOT
#define CHATBOT
#include "ChatBot.hpp"
#endif

class EchoChatBot : public ChatBot {
  
public:
  EchoChatBot(std::string name, std::queue<std::string> &message_queue);
  void on_message(std::string &message);

};
