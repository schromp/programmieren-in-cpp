#include <atomic>
#include <condition_variable>
#include <mutex>
#include <queue>
#include <string>
#include <thread>
#include <vector>

class ChatBot;

class Chat {
private:
  std::vector<ChatBot> bots;

public:
  ~Chat();
  void sendMessage(const std::string &message, const std::string &name);
  // void attachBot(ChatBot &bot);
  // void detachBot(ChatBot &bot);
  void shutdown();
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

  void runLoop();

public:
  ChatBot(std::string name, Chat *chat);
  ~ChatBot();
  void onMessage(const std::string &message);
  const std::string &getName();
  void shutdown();

protected:
  virtual void onProcessMessage(std::string &message) = 0;
  void sendMessage(std::string &message);
};

/**
 * @brief a bot that echos everything starting with echo and not containing ?
 */
class EchoChatBot : public ChatBot {
public:
  EchoChatBot(std::string name, Chat *chat) : ChatBot(name, chat) {}

private:
  /**
   * @brief processes given message and echos it message contains echo and
   * doesnt contain ?. it also adds a ? at the end
   *
   * @param message message to be processed
   */
  void onProcessMessage(std::string &message) override {
    if (message.rfind("echo", 0) == 0 &&
        message.find("?") != std::string::npos) {
      std::string transformed = message;
      transformed.append("?");
      sendMessage(transformed);
    }
  }
};
