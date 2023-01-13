// #include <algorithm>
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
Chat::~Chat() {
  // TODO: sleep for 6 seconds
  // std::for_each(bots.begin(), bots.end(), std::mem_fn(&std::thread::join));
}

/**
 * @brief interpret the message and send broadcast message or call command
 *
 * @param message
 * @param name
 */
void Chat::sendMessage(const std::string &message, const std::string &name) {
  if (name != "user") {
    std::cout << name << ":" << message << std::endl;
  } else {
    if (message.rfind("bot:") == 0) {
      std::string sub = message.substr(4);
      if (sub.rfind("echo,") == 0) {
        std::string new_name = sub.substr(6);
        EchoChatBot echo_bot(new_name, this);
        // this->attachBot(echo_bot);
      } else if (sub.rfind("quiz,") == 0) {
      }
    } else if (message == "exit") {
      shutdown();
    }
  }
}

/**
 * @brief insert the bot into managed vector
 *
 * @param bot
 */
// void Chat::attachBot(ChatBot &bot) { bots.push_back(bot); }
//
// /**
//  * @brief shutdown the bot and remoove it from the list
//  *
//  * @param bot
//  */
// void Chat::detachBot(ChatBot bot) {}
//
// void Chat::shutdown() {
//   std::for_each(bots.begin(), bots.end(),
//                 [&](ChatBot &bot) { bot.shutdown(); });
// }
