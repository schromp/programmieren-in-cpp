#include <ostream>

class GameBoard {
private:
  int moves = 0;
  int board[3][3] = {};

public:
  /**
   * @brief convert place on field into corresponding char
   *
   * @param int row
   * @param int collumn
   *
   * @return converted char(X or O)
   */
  char into_char(int, int) const;

  /**
   * @brief place mark onto board
   *
   * @param int row
   * @param int col
   * @param int value
   */
  void insert(int, int, int);

  /**
   * @brief is field free?
   *
   * @param int x
   * @param int y
   *
   * @return free or not free
   */
  bool isFree(int, int);

  /**
   * @brief gets winner of game
   *
   *
   * @return winner: 0: no winner yet, 1: player one, 2: player two, 3: draw
   */
  int getWinner();

  /**
   * @brief are there still moves to be played?
   *
   * @return moves or no moves
   */
  bool hasAvailableMoves();

  /**
   * @brief overload <<
   *
   * @param cout
   * @param board
   *
   * @return cout to be used further
   */
  friend std::ostream &operator<<(std::ostream &cout, const GameBoard &board);
};
