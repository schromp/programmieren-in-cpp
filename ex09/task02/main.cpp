#include <iostream>
#include <string>

#include "include/Chat.hpp"

int main(void) {

  Chat chat;

  std::string user_message;
  bool isRunning = true;

  while (isRunning) {
    std::cin >> user_message;

    if (user_message.rfind("bot:") == 0) {
      std::string sub = user_message.substr(4);
      if (sub.rfind("echo,") == 0) {
        std::string new_name = sub.substr(6);
        EchoChatBot echo_bot(new_name, &chat);
        chat.attachBot(echo_bot);
      } else if (sub.rfind("quiz,") == 0) {
        std::string new_name = sub.substr(6);
        QuizChatBot quiz_bot(new_name, &chat);
        chat.attachBot(quiz_bot);
      } else if (sub.rfind("counter,") == 0) {
        std::string new_name = sub.substr(6);
        CounterChatBot bot(new_name, &chat);
        chat.attachBot(bot);
      } else if (sub.rfind("delay,") == 0) {
        std::string new_name = sub.substr(6);
        DelayChatBot bot(new_name, &chat);
        chat.attachBot(bot);
      } else if (sub.rfind("prime,") == 0) {
        std::string new_name = sub.substr(6);
        PrimeChatBot bot(new_name, &chat);
        chat.attachBot(bot);
      }
    } else if (user_message == "exit") {
      isRunning = false;
    } else {
      chat.sendMessage(user_message, "user");
    }
  }
}
