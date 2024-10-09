// --------------------------------------------------------------------------
// Filename: CommandQuit.h
// Description: Class representing the quit command
//
//

// --------------------------------------------------------------------------

#ifndef QUIT_H
#define QUIT_H

#include "Command.h"

// --------------------------------------------------------------------------
// CommandQuit Class
// represents the command quit
//
class CommandQuit : public Command
{
private:
  // ----------------------------------------------------------------------
  // private copy constructor
  CommandQuit(const CommandQuit &other);

  // ----------------------------------------------------------------------
  // constant for the good bye text
  static const std::string GOOD_BYE_TEXT;

public:
  // ----------------------------------------------------------------------
  // constructor
  CommandQuit(const std::string &command_name, Game *board);

  // ----------------------------------------------------------------------
  // executes the command quit, gives out an good bye message via std::cout
  // and sets Game::game_runs_ to false
  //
  // @param params has to be an empty vector, else quit gives back an error
  // code
  // @return returns an error code
  //

  void execute(std::vector<std::string> &params);
  // ----------------------------------------------------------------------
  // destructor
  virtual ~CommandQuit();
};

#endif // QUIT_H
