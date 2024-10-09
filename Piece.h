// --------------------------------------------------------------------------
// Filename: Piece.h
// Description: Class representing a piece for a game
//
//
//

// --------------------------------------------------------------------------
#ifndef PIECE_H_
#define PIECE_H_

#include "Player.h" // Included for struct Color
#include <string>

class Game;

// --------------------------------------------------------------------------
enum MovementCodes
{
  CAPTURED = 1,
  CAPTURED_TRANSFORMATION = 2,
  PIECE_IN_THE_WAY = 3,
  ERROR_NO_OWN_PIECE_AT_START = 4,
  TARGET_NOT_REACHABLE = 8,
  OWN_PIECE_AT_TARGET = 16,
  ERROR_OUT_OF_FIELD = 32,

  CHECKMATE = 64,
  STALEMATE = 128,
  CHECK = 256,

  MOVE_SUCCESS = 512,
  MOVE_SUCCESS_TRANSFORMATION = 513,
  ENPASSANTE = 1024,
  ROCHADE = 2048
};

class Piece
{
private:
  // ----------------------------------------------------------------------
  // private copy constructor
  Piece(const Piece &);

protected:
  // ----------------------------------------------------------------------
  // position of the piece on the board
  //
  Point position_;

  // ----------------------------------------------------------------------
  // Color of the piece
  //
  Color color_;
  // ----------------------------------------------------------------------
  // Game in which the piece is
  //
  Game *board_;

  // ----------------------------------------------------------------------
  // this player owns the piece
  //
  Player *player_;

  // ----------------------------------------------------------------------
  // true if the piece has already moved once in the game
  //
  bool has_moved_;

  // ----------------------------------------------------------------------
  // Checks whether a position is on the board and not blocked.
  // @param end_point target position
  // @param field 8x8 2D Array of Piece-Pointer describing the current board
  // @return movement code
  //
  int field_reachable(Point end_point, Piece ***field) const;

  // ----------------------------------------------------------------------
  // Returns absolute value of an integer.
  // @param x input number
  // @return |x|
  //
  int abs(int x);

public:
  // ----------------------------------------------------------------------
  // Constructor
  // Sets the given attributes.
  // If a valid player pointer is given, its color will be taken, else the
  // default color is BLACK.
  // @param position sets position on board
  // @param board is a pointer to the game it is set on
  // @param player defines the owner of the piece
  //
  Piece(Point &position, Game *board, Player *player);

  // ----------------------------------------------------------------------
  // Moves the piece on the board.
  // This sets the piece's position to the given one and sets the attribute
  // has_moved_ to true. This will not perform any checks.
  // @param position target position
  //
  void moveToPosition(Point &position);

  // ----------------------------------------------------------------------
  // Checks whether a move is pseudo-legal.
  // This method checks whether a move to the given field is theoretically
  // possible, but does not consider endangering the own king.
  // @param start_point position to start the move from (in case the
  // temporary position does not match the stored one)
  // @param end_point target position
  // @param field 8x8 2D Array of Piece-Pointer describing the current board
  // @return movement code
  //
  virtual int move_possible(Point start_point,
                            Point end_point,
                            Piece ***field) = 0;

  // ----------------------------------------------------------------------
  // Checks whether a move is pseudo-legal.
  // This method checks whether a move to the given field is theoretically
  // possible, but does not consider endangering the own king.
  // It simply calls move_possible with the Piece's position as start point
  // @param end_point target position
  // @param field 8x8 2D Array of Piece-Pointer describing the current board
  // @return movement code
  //
  int move_possible(Point end_point, Piece ***field);

  // ----------------------------------------------------------------------
  // Returns a string as an identifier.
  // It is uppercase for white and lower case for black.
  // @return PieceId as string
  //
  virtual std::string toString() = 0;

  // ----------------------------------------------------------------------
  // Getter Methods
  //
  Color getColor();

  Point getPosition();

  Player *getPlayer() const;

  bool getHasMoved();

  int getX();

  int getY();

  // -----------------------------------------------------------------------
  // Setter Methods
  //
  void setColor(Color color);

  void setHasMoved(bool has_moved);

  // ----------------------------------------------------------------------
  // destructor
  virtual ~Piece();
};

#endif // PIECE_H_INCLUDED
