#ifndef COMPUTERPLAYER_H
#define COMPUTERPLAYER_H
#include "include/ComputerPlayer.hpp"
#include <iostream>
#endif
#include <stack>

ComputerPlayer::ComputerPlayer(int number, Mode mode)
    : number(number), mode(mode) {}

void ComputerPlayer::play(GameBoard &board) {
  if (mode == RANDOM) {
    random_move(board);
  } else if (mode == MINIMAX) {
    minimax_move(board);
  }
}

void ComputerPlayer::random_move(GameBoard &board) {
  int row = rand() % 3;
  int col = rand() % 3;
  while (!board.isFree(row, col)) {
    row = rand() % 3;
    col = rand() % 3;
  }
  board.insert(row, col, number);
}

struct Move {
  int row;
  int col;
  int score;
};

Move minimax(GameBoard &board, bool player1) {

  std::stack<Move> scores;

  for (int i = 1; i <= 3; i++) {
    for (int j = 1; j <= 3; j++) {
      if (board.isFree(i, j)) {
        board.insert(
            i, j,
            player1
                ? 1
                : 2); // play move so it can be used further down the recursion

        int winner = board.getWinner();
        if (player1 && winner == 1) {
          printf("w: 1\n");
          scores.push(Move{i, j, 10}); 
        } else if (!player1 && winner == 2) {
          printf("w: 2\n");
          scores.push(Move{i, j, -10}); 
        }

        std::cout << board;
        scores.push(minimax(board, !player1)); // FIX:

        board.insert(i, j, 0); // revert move so board is not changed
      }
    }
  }

  // FIX:
  Move best = Move{5, 5, player1 ? -10 : 10};
  printf("Scores: %lu\n", scores.size());

  while (!scores.empty()) {
    Move move = scores.top();
    if (player1) {
      if (move.score > best.score) {
        best = move;
        scores.pop();
      }
    } else {
      if (move.score < best.score) {
        best = move;
        scores.pop();
      }
    }
  }

  printf("Best: %d, %d, %d\n", best.row, best.col, best.score);
  std::cout << board;
  printf("upstairs\n");
  return best;
}

/**
 * @brief plays move with minimax algorithm
 *
 * @param board
 */
void ComputerPlayer::minimax_move(GameBoard &board) {
  Move move = minimax(board, (this->number == 1 ? true : false));
  board.insert(move.row, move.col, this->number);
}
