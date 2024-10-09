// --------------------------------------------------------------------------
// Filename: CommandView.h
// Description: Class representing the view command
//
//

// --------------------------------------------------------------------------

#ifndef VIEW_H
#define VIEW_H
#include "Command.h"

using std::string;

// --------------------------------------------------------------------------
// CommandView Class
// represents the command view
//
class CommandView : public Command
{
private:
  // ----------------------------------------------------------------------
  // Private copy constructor
  CommandView(const CommandView &other);

  // ----------------------------------------------------------------------
  // string constants for the grafical view of the table
  static const string HEADER_LINE;
  static const string SEPERATING_CHAR;
  static const string BLANK_CHAR;

public:
  // ----------------------------------------------------------------------
  // constructor
  CommandView(const string &command_name, Game *board);

  // ----------------------------------------------------------------------
  // executes the view command, it gives out the layout of the game per cout
  //
  // @param board The board where action should be performed on
  // @param params the param vector has to be empty or the function will
  // return an error code
  // @return returns an error code
  //
  void execute(std::vector<std::string> &params);

  // ----------------------------------------------------------------------
  // executes the status command, it gives out the name of the current
  // player per cout
  //
  // @param params the param vector has to be empty or the function will
  // return an error code
  // @return returns an error code
  //
  virtual ~CommandView();
};

#endif // VIEW_H
