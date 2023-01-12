#include "include/GameBoard.hpp"
#include <iostream>

void GameBoard::insert(int x, int y, int value) {
  moves += 1;
  board[x - 1][y - 1] = value;
}

bool GameBoard::isFree(int x, int y) { return board[x - 1][y - 1] == 0; }

bool GameBoard::hasAvailableMoves() { return moves <= 9; }

int GameBoard::amountAvailableMoves() {
  return moves;
}

int GameBoard::getWinner() {
  // rows 1-3
  if (board[0][0] == board[0][1] && board[0][0] == board[0][2]) {
    return board[0][0];
  } else if (board[1][0] == board[1][1] && board[1][0] == board[1][2]) {
    return board[1][0];
  } else if (board[2][0] == board[2][1] && board[2][0] == board[2][2]) {
    return board[2][0];
    // cols 1-3
  } else if (board[0][0] == board[1][0] && board[0][0] == board[2][0]) {
    return board[0][0];
  } else if (board[1][0] == board[1][1] && board[1][0] == board[1][2]) {
    return board[1][0];
  } else if (board[2][0] == board[2][1] && board[2][0] == board[2][2]) {
    return board[0][2];
    // diagonals 1-2
  } else if (board[0][0] == board[1][1] && board[0][0] == board[2][2]) {
    return board[0][0];
  } else if (board[2][0] == board[1][1] && board[2][0] == board[0][2]) {
    return board[2][0];
  } else if (hasAvailableMoves()) {
    return 0;
  } else {
    return 3;
  }
}

char GameBoard::into_char(int row, int col) const {
  if (board[row][col] == 1) {
    return 'X';
  } else if (board[row][col] == 2) {
    return 'O';
  } else {
    return ' ';
  }
}

// TODO: implement print
std::ostream &operator<<(std::ostream &cout, const GameBoard &board) {
  printf("     1   2   3   \n");
  printf("   ------------- \n");
  printf(" 1 | %c | %c | %c | \n", board.into_char(0, 0), board.into_char(0, 1),
         board.into_char(0, 2));
  printf("   ------------- \n");
  printf(" 2 | %c | %c | %c | \n", board.into_char(1, 0), board.into_char(1, 1),
         board.into_char(1, 2));
  printf("   ------------- \n");
  printf(" 3 | %c | %c | %c | \n", board.into_char(2, 0), board.into_char(2, 1),
         board.into_char(2, 2));
  printf("   ------------- \n");
  return cout;
}

