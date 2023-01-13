#include <queue>
#include <string>

#ifndef CHATBOT
#define CHATBOT
#include "ChatBot.hpp"
#endif

class Chat {
  bool running;
  std::queue<ChatBot> bots;
  void on_message();

public:
  Chat() : running(true) {}
  std::queue<std::string> message_queue;
  void shutdown();
  bool is_running() { return running; }
  void parse_message(std::string message, std::string name);
};
