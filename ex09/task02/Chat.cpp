// #include <algorithm>
#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <mutex>
#include <string>
#include <thread>
#include <utility>
#include <vector>

#include "include/Chat.hpp"

/**
 * @brief call detach and join all threads
 */
Chat::~Chat() { this->shutdown(); }

/**
 * @brief interpret the message and send broadcast message or call command
 *
 * @param message
 * @param name
 */
void Chat::sendMessage(const std::string &message, const std::string &name) {
  std::for_each(bots.begin(), bots.end(), [&message, &name](ChatBot *cb) {
    if (name != "user") {
      std::cout << name << ":" << message << std::endl;
    }
    cb->onMessage(message);
  });
}


/**
 * @brief shuts down the chat - shutsdown all bots
 */
void Chat::shutdown() {
  // TODO: wait 6 seconds
  while (!bots.empty()) {
    bots.pop_back();
  }
}

/**
 * @brief insert the bot into managed vector
 *
 * @param bot
 */
void Chat::attachBot(ChatBot &bot) { bots.push_back(&bot); }

/**
 * @brief shutdown the bot and remoove it from the list
 *
 * @param bot
 */
void Chat::detachBot(ChatBot &bot) {}
