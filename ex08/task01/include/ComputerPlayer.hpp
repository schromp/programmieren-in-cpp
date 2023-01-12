#ifndef PLAYER_H
#define PLAYER_H
#include "Player.hpp"
#endif

enum Mode {
  RANDOM,
  MINIMAX,
};

class ComputerPlayer : public Player {
private:
  Mode mode;
  int number;

public:
  ComputerPlayer(int, Mode);
  void play(GameBoard &);
  void random_move(GameBoard &);
  void minimax_move(GameBoard &);
};
