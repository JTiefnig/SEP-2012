// --------------------------------------------------------------------------
// Filename: CommandMove.h
// Description: Class representing the move command
//
//

// --------------------------------------------------------------------------

#ifndef COMMANDBOMB_H
#define COMMANDBOMB_H

#include "ChessCommand.h"
#include <string>
#include <vector>

using std::string;
using std::vector;

#include "Game.h" // Included for struct Point

class Player;

class CommandBomb : public ChessCommand
{

public:
  CommandBomb(std::string command_name, ChessGame *board);

  virtual ~CommandBomb(void);

  // ----------------------------------------------------------------------
  // executes the command move, moves a chess piece on the board
  // throws exceptions in case of fail
  // @param params must contain two strings: start and end point
  void execute(std::vector<std::string> &params);
};

#endif // ifndef COMMANDMOVE_H
