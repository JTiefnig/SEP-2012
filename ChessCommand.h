// --------------------------------------------------------------------------
// Filename: ChessCommand.h
// Description: Basic Class representing a Chess Command
//
//

// --------------------------------------------------------------------------

#ifndef CHESSCOMMAND_H_INCLUDED
#define CHESSCOMMAND_H_INCLUDED

#include "Command.h"
#include <string>

class ChessGame;

class ChessCommand : public Command
{
public:
  // ----------------------------------------------------------------------
  // Constructor
  ChessCommand(std::string name, ChessGame *board);
  // ----------------------------------------------------------------------
  // Destructor
  virtual ~ChessCommand(void);

protected:
  // ----------------------------------------------------------------------
  // a pointer to the game where the command should be performed on
  ChessGame *board_;
};

#endif // ifndef CHESSCOMMAND_H_INCLUDED
