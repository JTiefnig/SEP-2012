// --------------------------------------------------------------------------
// Filename: PieceBishop.cpp
//
//
//

// --------------------------------------------------------------------------

#include "PieceBishop.h"
#include <string>

const std::string PieceBishop::IDENTIFIER = "b";

PieceBishop::PieceBishop(Point &position, Game *board, Player *player) : Piece(position, board, player)
{
}

PieceBishop::~PieceBishop(void)
{
}

std::string PieceBishop::toString()
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

int PieceBishop::move_possible(Point start_point,
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
  if (abs(delta_x) != abs(delta_y))
  {
    return TARGET_NOT_REACHABLE;
  }

  int sign_x = delta_x > 0 ? 1 : -1;
  int sign_y = delta_y > 0 ? 1 : -1;
  // move along the bishops path
  for (int counter = 1; counter < abs(delta_x); counter++)
  {
    int x_position = start_point.x_coordinate_ + counter * sign_x;
    int y_position = start_point.y_coordinate_ + counter * sign_y;
    if (field[x_position][y_position] != 0)
    {
      return PIECE_IN_THE_WAY; // something is blocking
    }
  }

  // field not empty
  if (field[end_point.x_coordinate_][end_point.y_coordinate_] != 0)
  {
    // is own piece?
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
