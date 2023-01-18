#include <atomic>
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <ostream>
#include <queue>
#include <string>
#include <thread>
#include <vector>
#include <fstream>

class ChatBot;

class Chat {
private:
  std::vector<ChatBot *> bots;
  bool running;

public:
  ~Chat();
  void sendMessage(const std::string &message, const std::string &name);
  void attachBot(ChatBot &bot);
  void detachBot(ChatBot &bot);
  void shutdown();
  bool is_running();
};

class ChatBot {
private:
  std::string name;
  Chat *chat;
  std::queue<std::string> message;
  std::mutex queueMutex;
  std::atomic<bool> shouldTerminate;
  std::condition_variable condition;
  std::thread workerThread;

public:
  ChatBot(std::string name, Chat *chat);
  ~ChatBot();
  void operator()() const;
  void onMessage(const std::string &message);
  const std::string &getName();
  void shutdown();

protected:
  void runLoop();
  virtual void onProcessMessage(std::string &message) = 0;
  void sendMessage(std::string &message);
};

/**
 * @brief a bot that echos everything starting with echo and not containing ?
 */
class EchoChatBot : public ChatBot {
public:
  /**
   * @brief constructor
   *
   * @param name
   * @param chat
   */
  EchoChatBot(std::string name, Chat *chat) : ChatBot(name, chat) {}

  /**
   * @brief overload() to start class
   *
   * @param name
   * @param chat
   */
  void operator()(std::string name, Chat *chat) const {
    EchoChatBot echo(name, chat);
    echo.runLoop();
  }

private:
  /**
   * @brief processes given message and echos it message contains echo and
   * doesnt contain ?. it also adds a ? at the end
   *
   * @param message message to be processed
   */
  void onProcessMessage(std::string &message) override {
    if (message.rfind("echo") == 0) {
      std::string trans = message;
      trans.append("?");
      sendMessage(trans);
    }
  }
};

/**
 * @brief a bot that writes message delayed
 */
class DelayChatBot : public ChatBot {
public:
  /**
   * @brief constructor
   *
   * @param name
   * @param chat
   */
  DelayChatBot(std::string name, Chat *chat) : ChatBot(name, chat) {}

  /**
   * @brief overload() to start class
   *
   * @param name
   * @param chat
   */
  void operator()(std::string name, Chat *chat) const {
    DelayChatBot delay(name, chat);
    delay.runLoop();
  }

private:
  /**
   * @brief processes given message and echos it message contains echo and
   * doesnt contain ?. it also adds a ? at the end
   *
   * @param message message to be processed
   */
  void onProcessMessage(std::string &message) override {
    if (message.rfind("delayed") == 0) {
      std::string trans = message.substr(7);
      std::this_thread::sleep_for(std::chrono::seconds(2));
      sendMessage(trans);
    }
  }
};

/**
 * @brief a bot that counts to 3
 */
class CounterChatBot : public ChatBot {
public:
  /**
   * @brief constructor
   *
   * @param name
   * @param chat
   */
  CounterChatBot(std::string name, Chat *chat) : ChatBot(name, chat) {}

  /**
   * @brief overload() to start class
   *
   * @param name
   * @param chat
   */
  void operator()(std::string name, Chat *chat) const {
    CounterChatBot counter(name, chat);
    counter.runLoop();
  }

private:
  /**
   * @brief processes given message and echos it message contains echo and
   * doesnt contain ?. it also adds a ? at the end
   *
   * @param message message to be processed
   */
  void onProcessMessage(std::string &message) override {
    if (message == "counter") {
      std::cout << getName() << ": 1" << std::endl;
      std::this_thread::sleep_for(std::chrono::seconds(1));
      std::cout << getName() << ": 2" << std::endl;
      std::this_thread::sleep_for(std::chrono::seconds(1));
      std::cout << getName() << ": 3" << std::endl;
    }
  }
};

/**
 * @brief a bot that tells you if numbers are prime
 */
class PrimeChatBot : public ChatBot {
public:
  /**
   * @brief constructor
   *
   * @param name
   * @param chat
   */
  PrimeChatBot(std::string name, Chat *chat) : ChatBot(name, chat) {}

  /**
   * @brief overload() to start class
   *
   * @param name
   * @param chat
   */
  void operator()(std::string name, Chat *chat) const {
    PrimeChatBot prime(name, chat);
    prime.runLoop();
  }

private:
  /**
   * @brief processes given message and echos it message contains echo and
   * doesnt contain ?. it also adds a ? at the end
   *
   * @param message message to be processed
   */
  void onProcessMessage(std::string &message) override {
    if (message.rfind("isprime") == 0) {
      // TODO:
    }
  }
};

/**
 * @brief a bot that quizes you
 */
class QuizChatBot : public ChatBot {
public:
  /**
   * @brief constructor
   *
   * @param name
   * @param chat
   */
  QuizChatBot(std::string name, Chat *chat) : ChatBot(name, chat) {}

  /**
   * @brief overload() to start class
   *
   * @param name
   * @param chat
   */
  void operator()(std::string name, Chat *chat) const {
    QuizChatBot quiz(name, chat);
    quiz.runLoop();
  }

private:
  bool is_started;

  /**
   * @brief processes given message and echos it message contains echo and
   * doesnt contain ?. it also adds a ? at the end
   *
   * @param message message to be processed
   */
  void onProcessMessage(std::string &message) override {
    if (message.rfind("quiz") == 0) {
      // TODO:
      std::string trans = message.substr(4);

      std::string line;
      std::ifstream myfile;
      myfile.open(trans);

      if (!myfile.is_open()) {
        return;
      }

      while (getline(myfile, line)) {
        std::cout << getName() << ": Question A" << std::endl;
        std::cout << line << std::endl;
      }
    }
  }
};
