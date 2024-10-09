// --------------------------------------------------------------------------
// Filename: CommandEcho.h
// Description: Class representing the echo command
//
//

// --------------------------------------------------------------------------

#ifndef COMMANDECHO_H
#define COMMANDECHO_H

#include "Command.h"
#include <string>
#include <vector>

class Game;

using std::string;

// --------------------------------------------------------------------------
// CommandEcho Class
// represents the command echo
//
class CommandEcho : public Command
{
private:
  // ----------------------------------------------------------------------
  // private copy constructor
  CommandEcho(const CommandEcho &other);

public:
  // ----------------------------------------------------------------------
  // constructor
  CommandEcho(const string &command_name, Game *board);
  // ----------------------------------------------------------------------
  // executes the command echo, gives back the parameter
  //
  // @param board The board where action should be performed on
  // @param params has to be only one param, which will be rethrown to cout,
  // else echo gives back an error code
  // @return returns an error code
  void execute(std::vector<std::string> &params);
  // ----------------------------------------------------------------------
  // destructor
  virtual ~CommandEcho();
};

#endif // ECHO_H
