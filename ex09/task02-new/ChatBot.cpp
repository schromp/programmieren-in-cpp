#include "ChatBot.hpp"

ChatBot::ChatBot(std::string name, std::queue<std::string> &message_queue)
    : name(name), message_queue(message_queue) {}
