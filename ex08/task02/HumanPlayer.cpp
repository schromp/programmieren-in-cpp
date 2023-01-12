#include "include/HumanPlayer.hpp"
#include <cstdio>
#include <iostream>

HumanPlayer::HumanPlayer(int number) : number(number) {}

void HumanPlayer::play(GameBoard &board) {
  int col, row;
  std::cout << "Select a row:";
  std::cin >> row; // WARN: there might be a missing \n if the test is programmed badly :)
  std::cout << "Select a collumn:";
  std::cin >> col;

  if(board.isFree(row, col) && 0 < row && row < 4 && 0 < col && col < 4) {
    board.insert(row, col, number);
  } else {
    std::cout << "Invalid field selection" << std::endl;
    play(board);
  }
}
