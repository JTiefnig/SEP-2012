// --------------------------------------------------------------------------
// Filename: CommandHistory.cpp
//
//
//

// --------------------------------------------------------------------------

#include "ChessGame.h"
#include "CommandHistory.h"
#include "History.h"
#include "WrongUsageCommandException.h"
#include <iostream>

using std::cout;
using std::endl;

// --------------------------------------------------------------------------
void CommandHistory::execute(std::vector<std::string> &params)
{
  if (!params.empty())
  {
    throw Sep::WrongUsageCommandException();
  }
  board_->getGameHistory()->printHistory();
}

CommandHistory::CommandHistory(const string &command_name, ChessGame *board_) : ChessCommand(command_name, board_)
{
}

// --------------------------------------------------------------------------
CommandHistory::~CommandHistory()
{
}
