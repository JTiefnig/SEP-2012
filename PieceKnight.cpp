// --------------------------------------------------------------------------
// Filename: PieceKnight.cpp
//
//
//

// --------------------------------------------------------------------------

#include "PieceKnight.h"

const std::string PieceKnight::IDENTIFIER = "n";

PieceKnight::PieceKnight(Point &position, Game *board, Player *player) : Piece(position, board, player)
{
}

PieceKnight::~PieceKnight(void)
{
}

std::string PieceKnight::toString()
{
  if (this->getColor() == BLACK)
  {
    return this->IDENTIFIER;
  }

  if (this->getColor() == WHITE)
  {
    std::string s = IDENTIFIER;
    s[0] -= ('a' - 'A');
    return s;
  }
  return "";
}

int PieceKnight::move_possible(Point start_point,
                               Point end_point,
                               Piece ***field)
{
  // check if field lies outside the board or is blocked
  if (ERROR_OUT_OF_FIELD == field_reachable(end_point, field))
  {
    return ERROR_OUT_OF_FIELD;
  }
  int delta_x = end_point.x_coordinate_ - start_point.x_coordinate_;
  int delta_y = end_point.y_coordinate_ - start_point.y_coordinate_;
  // must move 2 in x and 1 in y (or vice versa)
  if (!(((abs(delta_x) == 2) && (abs(delta_y) == 1)) || ((abs(delta_x) == 1) && (abs(delta_y) == 2))))
  {
    return TARGET_NOT_REACHABLE;
  }

  // field not empty
  if (field[end_point.x_coordinate_][end_point.y_coordinate_] != 0)
  {
    // own piece on target?
    if (field[end_point.x_coordinate_][end_point.y_coordinate_]->getPlayer() == getPlayer())
    {
      return OWN_PIECE_AT_TARGET;
    }
    else
    {
      return CAPTURED;
    }
  }
  else
  {
    return MOVE_SUCCESS;
  }
}
