// --------------------------------------------------------------------------
// Filename: CommandHistory.h
// Description: Class representing the echo command
//
//

// --------------------------------------------------------------------------

#ifndef COMMANDHISTORY_H
#define COMMANDHISTORY_H

#include "ChessCommand.h"
#include <string>
#include <vector>

class Game;

using std::string;

// --------------------------------------------------------------------------
// CommandHistory Class
// represents the command echo
//
class CommandHistory : public ChessCommand
{
private:
  // ----------------------------------------------------------------------
  // private copy constructor
  CommandHistory(const CommandHistory &other);

public:
  // ----------------------------------------------------------------------
  // constructor
  CommandHistory(const string &command_name, ChessGame *board);
  // ----------------------------------------------------------------------
  // executes the command history, printing the game history
  //
  // @param params must be an empty vector
  void execute(std::vector<std::string> &params);
  // ----------------------------------------------------------------------
  // destructor
  virtual ~CommandHistory();
};

#endif // COMMANDHISTORY_H
