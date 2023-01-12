#ifndef GAMEBOARD_H
#define GAMEBOARD_H
#include "GameBoard.hpp"
#endif
#include <ostream>

class Player {
public:
  /**
   * @brief play a turn on the board
   *
   * @param board to be played on
   */
  virtual void play(GameBoard &) = 0;
};
