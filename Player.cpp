// --------------------------------------------------------------------------
// Player.cpp
//
//
//

// --------------------------------------------------------------------------

#include "Player.h"
#include <iostream>
#include <string>

// --------------------------------------------------------------------------

using std::string;

// --------------------------------------------------------------------------

const string Player::COLOR_STRINGS[] =
    {
        "Black", "White", "Red", "Green", "Blue", "Yellow", "Orange", "Brown"};

// --------------------------------------------------------------------------
Player::Player(Color color, string name) : color_(color), name_(name)
{
  bombed_ = 0;
}

// -------------------------
Player::Player(const Player &player) : color_(player.color_),
                                       name_(player.name_)
{
  bombed_ = 0;
}

// --------------------------------------------------------------------------
Player::Player()
{
  bombed_ = 0;
}

// --------------------------------------------------------------------------
Player::~Player()
{
}

// --------------------------------------------------------------------------
Color Player::getColor() const
{
  return color_;
}

// --------------------------------------------------------------------------
void Player::setColor(Color color)
{
  color_ = color;
}

// --------------------------------------------------------------------------
string Player::getName() const
{
  return name_;
}

// --------------------------------------------------------------------------
void Player::setName(string name)
{
  name_ = name;
}

// --------------------------------------------------------------------------
string Player::getFullName()
{
  string output_string = name_;

  output_string.append("(");
  output_string.append(COLOR_STRINGS[color_]); // select the proper string
                                               // using the enum
  output_string.append(")");
  return output_string;
}

std::ostream &operator<<(std::ostream &output, Player &player)
{
  return output << player.getFullName();
}

void Player::setBombed()
{
  bombed_ = 1;
}

bool Player::hasBombed()
{
  return bombed_;
}