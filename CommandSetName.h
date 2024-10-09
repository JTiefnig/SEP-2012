// --------------------------------------------------------------------------
// Filename: CommandSetName.h
// Description: Class representing the setname command
//
//

// --------------------------------------------------------------------------

#ifndef COMMANDSETNAME_H_
#define COMMANDSETNAME_H_

#include "ChessCommand.h"
#include <string>

using std::string;

// --------------------------------------------------------------------------
// CommandSetName Class
// represents the command echo
//
class CommandSetName : public ChessCommand
{
private:
  // ----------------------------------------------------------------------
  // private copy constructor
  CommandSetName(const CommandSetName &other);

  // ----------------------------------------------------------------------
  // info text when the name is set successfully
  static const string INFO;

  // ----------------------------------------------------------------------
  // a point and a newline character
  static const string POINT;

public:
  // ----------------------------------------------------------------------
  // constructor
  CommandSetName(const std::string &command_name, ChessGame *board_);

  // ----------------------------------------------------------------------
  // executes the command setname, changes the name of the currentplayer
  //
  // @param board The board where action should be performed on
  // @param params name which shall be set
  //
  void execute(std::vector<std::string> &params);

  // ----------------------------------------------------------------------
  // destructor
  virtual ~CommandSetName();
};

#endif /* COMMANDSETNAME_H_ */
