#include <mutex>
#include <utility>

#include "include/Chat.hpp"

ChatBot::ChatBot(std::string name, Chat *chat) : name(name), chat(chat) {
  // std::thread listener(&ChatBot::runLoop);
  // workerThread = std::move(listener);
}

ChatBot::~ChatBot() {}

const std::string &ChatBot::getName() { return this->name; }

void ChatBot::onMessage(const std::string &message) {}

void ChatBot::shutdown() {
  this->shouldTerminate = true;
}

void ChatBot::sendMessage(std::string &message) {
  this->chat->sendMessage(message, this->name);
}

void ChatBot::runLoop() {
  while(!this->shouldTerminate){
    // await message
    std::unique_lock<std::mutex> lock(this->queueMutex);
    condition.wait(lock);
  }
}
