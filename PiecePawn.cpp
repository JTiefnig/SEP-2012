// --------------------------------------------------------------------------
// Filename: PiecePawn.cpp
//
//
//

// --------------------------------------------------------------------------

#include "ChessGame.h"
#include "Game.h"
#include "PiecePawn.h"

const std::string PiecePawn::IDENTIFIER = "p";

PiecePawn::PiecePawn(Point &position, Game *board, Player *player) : Piece(position, board, player)
{
  turn_double_move_ = -2; // if a en passant capture would be try in turn 0
}

PiecePawn::~PiecePawn(void)
{
}

int PiecePawn::move_possible(Point start_point, Point end_point, Piece ***field)
{
  if (ERROR_OUT_OF_FIELD == field_reachable(end_point, field))
  {
    return ERROR_OUT_OF_FIELD;
  }

  Player *player = board_->getCurrentPlayer();

  int movement_distance = end_point.y_coordinate_ - start_point.y_coordinate_;
  int pawn_starting_row = 1;
  // white moves in the other direction as black
  if (color_ == WHITE)
  {
    movement_distance *= -1;
    pawn_starting_row = 6;
  }

  // move type depends on y distance
  switch (movement_distance)
  {
  case 1:
    // trying to move more than one sidewards
    if (abs(end_point.x_coordinate_ - start_point.x_coordinate_) > 1)
    {
      return TARGET_NOT_REACHABLE;
    }
    // try to capture
    if (abs(end_point.x_coordinate_ - start_point.x_coordinate_) == 1)
    {
      // try to capture en passant
      if (field[end_point.x_coordinate_][end_point.y_coordinate_] == 0 &&
          static_cast<ChessGame *>(board_)->getAdditionalRules())
      {
        return enPassant(field, start_point, end_point);
      }
      else if (field[end_point.x_coordinate_][end_point.y_coordinate_] !=
                   0 &&
               (end_point.y_coordinate_ == 0 ||
                end_point.y_coordinate_ == 7) &&
               static_cast<ChessGame *>(board_)->getAdditionalRules())
      {
        return CAPTURED_TRANSFORMATION;
      }
      // neither friend nor empty
      // field not empty
      else if (field[end_point.x_coordinate_][end_point.y_coordinate_] != 0)
      {
        // own piece on target?
        if (field[end_point.x_coordinate_][end_point.y_coordinate_]
                ->getPlayer() == getPlayer())
        {
          return TARGET_NOT_REACHABLE;
        }
        else
        {
          return CAPTURED;
        }
      }
      else
      {
        return TARGET_NOT_REACHABLE;
      }
    } // end of if move 1 sidewards
    // straight forward
    if (abs(end_point.x_coordinate_ - start_point.x_coordinate_) == 0)
    {
      // field not empty
      if (field[end_point.x_coordinate_][end_point.y_coordinate_] != 0)
      {
        // own piece on target?
        if (field[end_point.x_coordinate_][end_point.y_coordinate_]
                ->getPlayer() == getPlayer())
        {
          return OWN_PIECE_AT_TARGET;
        }
        else
        {
          // pawn can not capture straight forward.
          return TARGET_NOT_REACHABLE;
        }
      }
      if ((end_point.y_coordinate_ == 0 ||
           end_point.y_coordinate_ == 7) &&
          static_cast<ChessGame *>(board_)->getAdditionalRules())
      {
        return MOVE_SUCCESS_TRANSFORMATION;
      }
    }
    break;
  case 2:
    // trying to move sidewards as well as 2 forwards
    if (end_point.x_coordinate_ != start_point.x_coordinate_)
    {
      return TARGET_NOT_REACHABLE;
    }
    if (start_point.y_coordinate_ != pawn_starting_row)
    {
      // Trying to move 2 fields but not being on the first move
      return TARGET_NOT_REACHABLE;
    }
    if (field[end_point.x_coordinate_][end_point.y_coordinate_] != 0)
    {
      if (field[end_point.x_coordinate_][end_point.y_coordinate_]->getPlayer() == player)
      {
        return OWN_PIECE_AT_TARGET;
      }
      else // not player and not empty => enemy
      {
        return TARGET_NOT_REACHABLE;
      }
    }
    if (field[end_point.x_coordinate_][(end_point.y_coordinate_ +
                                        start_point.y_coordinate_) /
                                       2] !=
        0)
    {
      return PIECE_IN_THE_WAY;
    }

    turn_double_move_ = board_->getTurn();
    break;
  default:
    return TARGET_NOT_REACHABLE;
  }

  return MOVE_SUCCESS;
}

std::string PiecePawn::toString()
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

int PiecePawn::enPassant(Piece ***field, Point start_point,
                         Point end_point) const
{
  if (field[end_point.x_coordinate_][start_point.y_coordinate_] != 0)
  {
    Piece *neighbour_piece =
        field[end_point.x_coordinate_][start_point.y_coordinate_];
    // no check for enemy neccessary because of (turn - 1) condition
    if (neighbour_piece->toString() == "p" || neighbour_piece->toString() ==
                                                  "P")
    {
      if (static_cast<PiecePawn *>(neighbour_piece)->getTurnDoubleMove() ==
          (board_->getTurn() - 1))
      {
        return ENPASSANTE;
      }
    }
  }
  return TARGET_NOT_REACHABLE;
}

int PiecePawn::getTurnDoubleMove() const
{
  return turn_double_move_;
}
