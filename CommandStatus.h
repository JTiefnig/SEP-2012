// --------------------------------------------------------------------------
// Filename: CommandStatus.h
// Description: Class representing the status command
//
//

// --------------------------------------------------------------------------

#ifndef STATUS_H
#define STATUS_H

#include "Command.h"

using std::string;

// --------------------------------------------------------------------------
// CommandStatus Class
// represents the command status
//
class CommandStatus : public Command
{
private:
  // ----------------------------------------------------------------------
  // Private copy constructor
  CommandStatus(const CommandStatus &other);

public:
  // ----------------------------------------------------------------------
  // Constructor
  CommandStatus(const string &command_name, Game *board);

  // ----------------------------------------------------------------------
  // executes the status command, it gives out the name of the current
  // player per cout
  //
  // @param board The board where action should be performed on
  // @param params the param vector has to be empty or the function will
  // return an error code
  // @return returns an error code
  //
  void execute(std::vector<std::string> &params);

  // ----------------------------------------------------------------------
  // destructor
  virtual ~CommandStatus();
};

#endif // STATUS_H
