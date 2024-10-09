// --------------------------------------------------------------------------
// Filename: CommandSave.h
// Description: Class representing the save command
//
//

// --------------------------------------------------------------------------

#ifndef COMMANDSAVE_H
#define COMMANDSAVE_H

#include "ChessCommand.h"
#include <string>
#include <vector>

class Game;

using std::string;

// --------------------------------------------------------------------------
// CommandHistory Class
// represents the command save
//
class CommandSave : public ChessCommand
{
private:
  // ----------------------------------------------------------------------
  // Saves the maximum line length of history output
  //
  static const unsigned int MAXIMUM_LINE_LENGHT;

  // ----------------------------------------------------------------------
  // Defines the end of each meta string
  //
  static const string META_END;

  // ----------------------------------------------------------------------
  // Array which defines a collection of meta strings
  //
  static const string META_STRINGS[];

  // ----------------------------------------------------------------------
  // private copy constructor
  CommandSave(const CommandSave &other);

public:
  // ----------------------------------------------------------------------
  // constructor
  CommandSave(const string &command_name, ChessGame *board);
  // ----------------------------------------------------------------------
  // executes the command save, saves the history of the game
  //
  // @param board The board where action should be performed on
  // @param params has to be only one param, which is the name of the save
  // file
  void execute(std::vector<std::string> &params);
  // ----------------------------------------------------------------------
  // destructor
  virtual ~CommandSave();
};

#endif // COMMANDSAVE_H
