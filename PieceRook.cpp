// --------------------------------------------------------------------------
// Filename: PieceRook.cpp
//
//
//

// --------------------------------------------------------------------------

#include "PieceRook.h"

const std::string PieceRook::IDENTIFIER = "r";

PieceRook::PieceRook(Point &position, Game *board, Player *player) : Piece(position, board, player)
{
}

PieceRook::~PieceRook(void)
{
}

std::string PieceRook::toString()
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

int PieceRook::move_possible(Point start_point, Point end_point, Piece ***field)
{
  // check if field lies outside the board or is blocked
  if (ERROR_OUT_OF_FIELD == field_reachable(end_point, field))
  {
    return ERROR_OUT_OF_FIELD;
  }

  int delta_x = end_point.x_coordinate_ - start_point.x_coordinate_;
  int delta_y = end_point.y_coordinate_ - start_point.y_coordinate_;

  if (delta_x && delta_y) // try to move outside a straight line
  {
    return TARGET_NOT_REACHABLE;
  }
  if (delta_x) // move straight in x direction
  {
    int sign_x = delta_x / abs(delta_x);
    int y_position = start_point.y_coordinate_;
    for (int counter = 1; counter < abs(delta_x); counter++)
    {
      int x_position = start_point.x_coordinate_ + counter * sign_x;
      if (field[x_position][y_position] != 0)
      {
        return PIECE_IN_THE_WAY;
      }
    }
  }
  else // move straight in y direction
  {
    int sign_y = 0;
    if (delta_y)
    {
      sign_y = delta_y / abs(delta_y);
    }
    int x_position = start_point.x_coordinate_;
    for (int counter = 1; counter < abs(delta_y); counter++)
    {
      int y_position = start_point.y_coordinate_ + counter * sign_y;
      if (field[x_position][y_position] != 0)
      {
        return PIECE_IN_THE_WAY;
      }
    }
  }
  // field not empty
  if (field[end_point.x_coordinate_][end_point.y_coordinate_] != 0)
  {
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
