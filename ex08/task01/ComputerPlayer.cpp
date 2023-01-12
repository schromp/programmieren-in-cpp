#ifndef COMPUTERPLAYER_H
#define COMPUTERPLAYER_H
#include "include/ComputerPlayer.hpp"
#endif

ComputerPlayer::ComputerPlayer(int number, Mode mode)
    : number(number), mode(mode) {}

void ComputerPlayer::play(GameBoard &board) {
  // TODO: implement minimax algorithm
  if (mode == RANDOM) {
    random_move(board);
  }
}

void ComputerPlayer::random_move(GameBoard &board) {
  int row = rand() % 3;
  int col = rand() % 3;
  while (!board.isFree(row, col)) {
    row = rand() % 3;
    col = rand() % 3;
    printf("test\n");
  }
  board.insert(row, col, number);
}
