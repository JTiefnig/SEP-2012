// --------------------------------------------------------------------------
// Filename: PieceKing.cpp
//
//
//

// --------------------------------------------------------------------------

#include "ChessGame.h"
#include "PieceKing.h"
#include <iostream>
#include <string>

using std::string;
const std::string PieceKing::IDENTIFIER = "k";

PieceKing::PieceKing(Point &position, Game *board, Player *player) : Piece(position, board, player)
{
}

PieceKing::~PieceKing(void)
{
}

std::string PieceKing::toString()
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

int PieceKing::move_possible(Point start_point, Point end_point, Piece ***field)
{
  // check if field lies outside the board or is blocked
  if (ERROR_OUT_OF_FIELD == field_reachable(end_point, field))
  {
    return ERROR_OUT_OF_FIELD;
  }

  int delta_x = end_point.x_coordinate_ - start_point.x_coordinate_;
  int delta_y = end_point.y_coordinate_ - start_point.y_coordinate_;
  // 2 in x because rochade might be made
  if (abs(delta_y) > 1 || abs(delta_x) > 2)
  {
    return TARGET_NOT_REACHABLE;
  }

  int sign_x = delta_x > 0 ? 1 : -1;

  if (abs(delta_x) == 2) // rochade
  {
    if (!static_cast<ChessGame *>(board_)->getAdditionalRules())
    {
      // tried rochade although additional rules are not enabled
      return TARGET_NOT_REACHABLE;
    }
    if (getHasMoved())
    {
      // no rochade if king has already been moved before
      return TARGET_NOT_REACHABLE;
    }

    // run through all points in same row:
    for (int x = start_point.x_coordinate_ + sign_x;
         x >= 0 && x < board_->getBounds().x_coordinate_;
         x += sign_x)
    {
      if (field[x][position_.y_coordinate_])
      {
        if ((player_->getColor() == WHITE &&
             field[x][position_.y_coordinate_]->toString() == "R") ||
            (player_->getColor() == BLACK &&
             field[x][position_.y_coordinate_]->toString() == "r"))
        {
          if (field[x][position_.y_coordinate_]->getHasMoved())
          {
            // Tower has already made a move => no rochade
            return TARGET_NOT_REACHABLE;
          }
          return ROCHADE;
        }
        else
        {
          // some piece in the way and its not the own tower!
          return PIECE_IN_THE_WAY;
        }
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
