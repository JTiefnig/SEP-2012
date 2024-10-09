// --------------------------------------------------------------------------
// Filename: ChessCommand.cpp
//
//
//

// --------------------------------------------------------------------------

#include "ChessCommand.h"
#include <string>

class ChessGame;
// --------------------------------------------------------------------------
ChessCommand::~ChessCommand()
{
}
// --------------------------------------------------------------------------
ChessCommand::ChessCommand(std::string name, ChessGame *board) : Command(name), board_(board)
{
}
