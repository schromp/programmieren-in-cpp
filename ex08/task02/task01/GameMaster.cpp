#include "include/ComputerPlayer.hpp"
#include "include/HumanPlayer.hpp"
#include <iostream>

int getSelection() {
  std::cout << "Choose your game mode." << std::endl;
  std::cout << "(1) Human vs. Human" << std::endl;
  std::cout << "(2) Human vs. Computer (Minimax)" << std::endl;
  std::cout << "(3) Human vs. Computer (Random)" << std::endl;
  std::cout << "(4) Computer (Minimax) vs. Computer (Minimax)" << std::endl;
  std::cout << "(5) Exit Program" << std::endl;
  int input;
  std::cin >> input;
  return input;
}

void start(GameBoard board, Player &p1, Player &p2) {
  int winner = 0;
  std::cout << board;
  std::cout << "Player 1: X" << std::endl;
  std::cout << "Player 2: O" << std::endl;
  while (winner == 0) {
    std::cout << "Player 1's turn" << std::endl;
    p1.play(board);
    std::cout << board;
    winner = board.getWinner();
    if (winner != 0) {
      break;
    }
    std::cout << "Player 2's turn" << std::endl;
    p2.play(board);
    std::cout << board;
    winner = board.getWinner();
    if (winner != 0) {
      break;
    }
  }

  if (winner == 1) {
    printf("Winner is: Player 1 (X)\n");
  } else if (winner == 2) {
    printf("Winner is: Player 2 (O)\n");
  } else {
    printf("A draw!");
  }
}

int main() {

  bool playing = true;

  while (playing) {
    GameBoard board;
    int input = getSelection();
    if (input == 1) {
      HumanPlayer p1(1);
      HumanPlayer p2(2);
      start(board, p1, p2);
    } else if (input == 2) {
      HumanPlayer p1(1);
      ComputerPlayer p2(2, MINIMAX);
      start(board, p1, p2);
    } else if (input == 3) {
      HumanPlayer p1(1);
      ComputerPlayer p2(2, RANDOM);
      start(board, p1, p2);
    } else if (input == 4) {
      ComputerPlayer p1(1, MINIMAX);
      ComputerPlayer p2(2, MINIMAX);
      start(board, p1, p2);
    } else {
      playing = false;
    }
  }
}
