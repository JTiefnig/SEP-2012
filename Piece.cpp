// --------------------------------------------------------------------------
// Filename: Piece.cpp
//
//
//

// --------------------------------------------------------------------------

#include "Piece.h"
#include "Player.h"

#include <string>

using std::string;

// --------------------------------------------------------------------------
Piece::Piece(Point &position, Game *board, Player *player) : position_(position), board_(board), player_(player), has_moved_(false)
{
  if (player)
  {
    color_ = player->getColor();
  }
  else
  {
    color_ = BLACK;
  }
}

// --------------------------------------------------------------------------
Piece::~Piece()
{
}

Point Piece::getPosition()
{
  return position_;
}

Player *Piece::getPlayer() const
{
  return player_;
}

void Piece::moveToPosition(Point &position)
{
  this->position_ = position;
  has_moved_ = true;
}

int Piece::getX()
{
  return this->position_.x_coordinate_;
}

int Piece::getY()
{
  return this->position_.y_coordinate_;
}

void Piece::setColor(Color color)
{
  this->color_ = color;
}

Color Piece::getColor()
{
  return this->color_;
}

bool Piece::getHasMoved()
{
  return has_moved_;
}

int Piece::move_possible(Point end_point, Piece ***field)
{
  return move_possible(position_, end_point, field);
}
int Piece::field_reachable(Point end_point, Piece ***field) const
{
  if (end_point.x_coordinate_ > board_->getBounds().x_coordinate_ ||
      end_point.x_coordinate_ < 0 || end_point.y_coordinate_ > board_->getBounds().y_coordinate_ || end_point.y_coordinate_ < 0)
  {
    return ERROR_OUT_OF_FIELD;
  }

  // field is non null => could be enemy or own figure
  if (field[end_point.x_coordinate_][end_point.y_coordinate_] &&
      field[end_point.x_coordinate_][end_point.y_coordinate_]->getPlayer() ==
          player_) // would caputure own figure
  {
    return OWN_PIECE_AT_TARGET;
  }

  return MOVE_SUCCESS;
}

int Piece::abs(int x)
{
  if (x >= 0)
  {
    return x;
  }
  else
  {
    return -x;
  }
}
