// --------------------------------------------------------------------------
// Filename: Command.h
// Description: Class representing a general command
//
//

// --------------------------------------------------------------------------

#ifndef COMMAND_H_INCLUDED
#define COMMAND_H_INCLUDED

#include <string>
#include <vector>

class Game;

// --------------------------------------------------------------------------
// Command Class
// represents an abstract command for game
//
class Command
{
private:
  // ----------------------------------------------------------------------
  // Private copy constructor

  Command(const Command &original);

  // ----------------------------------------------------------------------
  // Private assignment operator

  Command &operator=(const Command &original);

  // ----------------------------------------------------------------------
  // Name of this command
  std::string command_name_;

protected:
  Game *board_;

public:
  // ----------------------------------------------------------------------
  // Constructor
  Command(std::string name, Game *board);

  // ----------------------------------------------------------------------
  // Constructor
  Command(std::string name);

  // ----------------------------------------------------------------------
  // Destructor

  virtual ~Command();

  // ----------------------------------------------------------------------
  // Executes the action.
  // @param params Parameters needed for the execution
  // @return Integer representing the success of the action
  virtual void execute(std::vector<std::string> &params) = 0;

  // ----------------------------------------------------------------------
  // Getter Methods
  const std::string &getName();
};

#endif // COMMAND_H_INCLUDED
