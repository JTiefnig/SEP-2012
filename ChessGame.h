// --------------------------------------------------------------------------
// ChessGame.h
// Description: Class representing a chess game
//
//
//

// --------------------------------------------------------------------------
//

#ifndef CHESSGAME_H_
#define CHESSGAME_H_

#include "Game.h"
#include <string>
#include <vector>

using std::vector;

class History;
class Piece;

// -----------------------------------------------------------------------------
// struct which contains all the data of a current move
//
typedef struct Move_
{
  Point start_point_; // the name states it
  Point end_point_;   // the name states it
  int move_error_;    // containing error code of movment
  bool captured_;     // true when an enemy has been captured
  bool check_;        // true when check is given (also true at checkmate)
  bool finished_;     // true when stalemate or checkmate
                      // (use check_ to differentiate)
  std::string piece_id_;
} Move;

class ChessGame : public Game
{
private:
  // ----------------------------------------------------------------------
  // Defines the end of a c string
  //
  static const char END_OF_ARGUMENT;

  // ----------------------------------------------------------------------
  // Defines the bounds of an chess board
  //
  static const Point CHESS_BOUNDS;

  // ----------------------------------------------------------------------
  // Question for the user in case of a pawn tranformation
  //
  static const std::string NEW_PIECE_QUESTION;

  // ----------------------------------------------------------------------
  // error message if the user gives no proper answer to the
  // NEW_PIECE_QUESTION
  //
  static const std::string WRONG_ANSWER;

  // ----------------------------------------------------------------------
  // message saying "wins!\n";
  //
  static const std::string PLAYER_WINS;

  // ----------------------------------------------------------------------
  // stalemate message
  //
  static const std::string STALEMATE_MESSAGE;

  // ----------------------------------------------------------------------
  // vector of the piece which are on the board
  // createBoardFromArguments
  vector<Piece *> temporary_captured_;

  // ----------------------------------------------------------------------
  // vector of possible moves which can be performed in the chess game
  //
  vector<Move> temporary_moves_;

  // ----------------------------------------------------------------------
  // if a player offers a draw dra_offered will be set on true
  //
  bool draw_offered_;

  // ----------------------------------------------------------------------
  // a imaginary board where the moves are tried on, and only when they are
  // possible the pieces will be set on the real board
  //
  Piece ***temporary_board_;

  // ----------------------------------------------------------------------
  // this will be set if the chess game runs with the bonus rules
  //
  bool additional_rule_;

  // ----------------------------------------------------------------------
  // class which saves the moves of the game for the history
  //
  History *game_history_;

  // ----------------------------------------------------------------------
  // interprets the input from cin and tries to choose and perform the
  // apropriate command
  //
  // @param command_string this is the user input from cin
  //
  void interpretCommandString(const string &command_string);

  // ----------------------------------------------------------------------
  // updates the temporary board (it loads the current board in the temporary
  // board)
  //
  void updateBoard();

  // ----------------------------------------------------------------------
  // perfoms a move on the temporary board
  //
  // @param starting_point point from which the piece should be moved
  // @param end_point position whereto the piece shold be moved
  //
  void move_temporary(const Point &starting_point, const Point &end_point);

  // ----------------------------------------------------------------------
  // reverse the last move which was performed on the temporary board
  //
  void undo_temporary_move();

  // ----------------------------------------------------------------------
  // checks if the position can be attacked by the enemy player (attacker)
  // position can be a field with a piece and without one
  //
  // @param position this is the position which should be checked if it could
  // be attacked
  // @param attacker this is the current enemy player
  // @return returns true if the field could be attacked, else it returns
  // false
  //
  bool canBeAttacked(Point position, Player *attacker) const;

  // ----------------------------------------------------------------------
  // returns the current enemy player
  //
  // @return a pointer to the current enemy player
  //
  Player *getEnemy() const;

  // ----------------------------------------------------------------------
  // returns the position of the king of the player
  //
  // @param Player* pointer of the player whos king should be found
  //
  // @return the position of the king
  //
  Point getTemporaryKingPosition(Player *) const;

  // ----------------------------------------------------------------------
  // returns the positon of the piece
  //
  // @param piece pointer to the piece which position should be found
  //
  // @return position of the piece on the board
  //
  Point getTemporaryPosition(Piece *piece);

  // ----------------------------------------------------------------------
  // creates and initialises the temporary board
  //
  void createTemporaryBoard();

  // ----------------------------------------------------------------------
  // prints the move in short (Sep) notation to cout
  //
  // @param move this is the move which is printed to cout
  //
  void printMoveMessage(Move &move);

  // ----------------------------------------------------------------------
  // checks if a checkmate or a stalemate happend and sets the move params to
  // the proper values
  //
  // @param move this is the move which is checked for checkmate or stalemate
  //
  void setWinStatus(Move &move);

  // ----------------------------------------------------------------------
  // creates proper Piece element based on Parameters
  //
  // @param id Representing a Chess Piece
  // @param player who ones the Piece
  // @param Postion of the Piece on Gameboard
  //
  // @return Pointer on Piece element
  //
  Piece *createPieceFromArguments(char piece_id, Player *owner,
                                  Point piece_position);

  // ----------------------------------------------------------------------
  // ask the player which new piece he want in case of pawn transformation
  //
  // @param position this is the position where the new piece will be set
  // @param owner this is the player who transforms the pawn
  //
  // @return Pointer on Piece element
  //
  Piece *askWhichPiece(Player *owner, Point position);

public:
  // ----------------------------------------------------------------------
  // converts the move struct to a string which contains the information of
  // the move which could be printed per cout
  //
  // @param move this is the move which will be converted to the string
  //
  // @return returns a string which has the informations of the move
  //
  std::string getMoveToString(Move move);

  History *getGameHistory();
  // ----------------------------------------------------------------------
  // Takes a setup string and creates the given board.
  // Setup string must have a form like Ne4Kd3 (for Knight on e4 and King on
  // d3). Errors due to unfinished strings or 2 figures on the same position
  // will throw an exception
  // @param setup string
  //
  void createBoardFromArguments(std::string argument_string);

  // ----------------------------------------------------------------------
  // Ends the turn and hands over to the next player.
  // This will switch the current player and add +1 to the number of turns.
  //
  void nextPlayer();

  // ----------------------------------------------------------------------
  // Moves a piece from start to end and organizes, all checks and logs.
  // It will check bounds, get the proper Piece, set up a temporary board
  // call the Piece->movePossible function to check for pseudo legality,
  // the perform a temporary move, check for attacks on the own king,
  // then check for possible check, mate or stalemate.
  // It will also call the corresponding output functions and add a valid
  // move to the history.
  // This function will throw exceptions for all errors occuring
  // @param start starting point
  // @param end target
  //
  void movePiece(Point &start, Point &end);

  // ----------------------------------------------------------------------
  // Checks whether there is any legal move the enemy can do in the temporary
  // situation.
  // @return true or false
  //
  bool enemyMovePossible();

  // ----------------------------------------------------------------------
  // Getter methods
  //
  bool getDrawOffered();

  bool getAdditionalRules();

  // ----------------------------------------------------------------------
  // Setter methods
  //
  void setDrawOffered(bool);

  void setGameFinished(bool);

  // ----------------------------------------------------------------------
  // constructor
  //
  ChessGame();

  // ----------------------------------------------------------------------
  // constructor
  //
  ChessGame(int, int, bool);

  void bomb(Point);

  // ----------------------------------------------------------------------
  // destructor
  //
  virtual ~ChessGame();
};

#endif // CHESSGAME_H_
