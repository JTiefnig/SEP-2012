// --------------------------------------------------------------------------
// PieceQueen.h
//
//
//

// --------------------------------------------------------------------------

#ifndef PIECEQUEEN_H_
#define PIECEQUEEN_H_

#include "Piece.h"
#include <string>

class PieceQueen : public Piece
{
private:
  // ----------------------------------------------------------------------
  // Identifier describing the piece type
  //
  static const std::string IDENTIFIER;

public:
  // ----------------------------------------------------------------------
  // Constructor
  // Will only call the corresponding Piece Constructor.
  // @param position sets position on board
  // @param board is a pointer to the game it is set on
  // @param player defines the owner of the piece
  //
  PieceQueen(Point &position, Game *board, Player *player);
  // ----------------------------------------------------------------------
  // Destructor
  //
  ~PieceQueen(void);

  // ----------------------------------------------------------------------
  // Returns a string as an identifier.
  // It is uppercase for white and lower case for black.
  // @return PieceId as string
  //
  std::string toString();

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
  int move_possible(Point start_point, Point end_point, Piece ***field);
};

#endif // ifndef PIECEQUEEN_H_
