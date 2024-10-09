// --------------------------------------------------------------------------
// Filename: CommandMove.h
// Description: Class representing the move command
//
//

// --------------------------------------------------------------------------

#ifndef COMMANDMOVE_H
#define COMMANDMOVE_H

#include "ChessCommand.h"
#include <string>
#include <vector>

using std::string;
using std::vector;

#include "Game.h" // Included for struct Point

class Player;

class CommandMove : public ChessCommand
{
private:
  // ----------------------------------------------------------------------
  // converts the input params to a start position and a end position#
  // checks if the params are ok
  //
  // @param params this are the input params of the move command (normal
  // start and end position of the move, 2 params)
  // @param starting point this point will be overwritten with the
  // position of the first param
  // @param starting point this point will be overwritten with the
  // position of the second param
  //
  void convertToPoints(vector<std::string> &params,
                       Point &starting_point,
                       Point &end_point);

public:
  // ----------------------------------------------------------------------
  // constructor
  CommandMove(std::string command_name, ChessGame *board);
  // ----------------------------------------------------------------------
  // destructor
  virtual ~CommandMove(void);

  // ----------------------------------------------------------------------
  // executes the command move, moves a chess piece on the board
  // throws exceptions in case of fail
  // @param params must contain two strings: start and end point
  void execute(std::vector<std::string> &params);
};

#endif // ifndef COMMANDMOVE_H
