#include <queue>
#include <string>

class ChatBot {
private:
  std::string name;
protected:
  std::queue<std::string> &message_queue;
  
public:
  ChatBot(std::string name, std::queue<std::string> &message_queue);

  virtual void on_message(std::string &message);

};
