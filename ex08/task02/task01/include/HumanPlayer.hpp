#ifndef PLAYER_H
#define PLAYER_H
#include "Player.hpp"
#endif

class HumanPlayer : public Player {
private:
  int number;

public:

  /**
   * @brief constructor
   *
   * @param int player number
   */
  HumanPlayer(int);
  
  virtual void play(GameBoard &);
};
