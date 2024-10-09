// --------------------------------------------------------------------------
// Player.h
//
//
//

// --------------------------------------------------------------------------

#ifndef PLAYER_H_
#define PLAYER_H_

#include "Game.h" // included for declaration of struct Point
#include <iostream>
#include <string>
#include <vector>

class Piece;

using std::string;

// The following enum contains all the possible colors for a player
enum Color
{
  BLACK,
  WHITE,
  RED,
  GREEN,
  BLUE,
  YELLOW,
  ORANGE,
  BROWN
};
// ------------------------------------------------------------------------
// Player class
// class that describes a player, by his name and color
//
class Player
{
private:
  bool bombed_;

private:
  // ----------------------------------------------------------------------
  // color of player
  //
  Color color_;

  // ----------------------------------------------------------------------
  // name of player
  //
  string name_;

  // ----------------------------------------------------------------------
  // this array will contain the names
  // of the colors going with the correspondent enum Color value
  //
  static const string COLOR_STRINGS[];

public:
  void setBombed();

  bool hasBombed();
  // ----------------------------------------------------------------------
  // Copy Constructor
  //
  Player(const Player &);

  // ----------------------------------------------------------------------
  // Default Constructur
  //
  Player();

  // ----------------------------------------------------------------------
  // Destructor
  //
  ~Player();

  // ----------------------------------------------------------------------
  // Constructor
  // Creates a new Player given the following attributes
  // @param color Color of the new player (given as one of the enum values)
  // @param name Name of the new player (given as a std::string)
  //
  Player(Color color, string name);

  // ----------------------------------------------------------------------
  // Returns the player's color
  //
  Color getColor() const;

  // ----------------------------------------------------------------------
  // Sets the player's color
  // @param color new Color
  //
  void setColor(Color color);

  // ----------------------------------------------------------------------
  // Returns the player's name
  //
  string getName() const;

  // ----------------------------------------------------------------------
  // Sets the player's name
  // @param name new Name
  //
  void setName(string name);

  // ----------------------------------------------------------------------
  // Returns the player's name and color in the form [name]([color])
  // @return full Name
  //
  string getFullName();
};

// ----------------------------------------------------------------------
// operator that gives out the full name of the player
//
std::ostream &operator<<(std::ostream &output, Player &player);

#endif // PLAYER_H_
