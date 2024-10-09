// --------------------------------------------------------------------------
// Filename: CommandSetName.cpp
//
//
//

// --------------------------------------------------------------------------

#include "ChessGame.h"
#include "CommandSetName.h"
#include "Player.h"

#include <iostream>
#include <vector>

#include "GameFinishedException.h"
#include "WrongUsageCommandException.h"

const string CommandSetName::INFO = "Name set: ";
const string CommandSetName::POINT = ".\n";

// --------------------------------------------------------------------------
void CommandSetName::execute(std::vector<std::string> &params)
{
  if (params.size() != 1)
  {
    throw Sep::WrongUsageCommandException();
  }
  if (board_->getGameFinished())
  {
    throw Sep::GameFinishedException();
  }
  vector<Player *> players = board_->getPlayers();
  board_->getCurrentPlayer()->setName(params[0]);
  std::cout << INFO << *(board_->getCurrentPlayer()) << POINT;
}

// --------------------------------------------------------------------------
CommandSetName::CommandSetName(const std::string &command_name,
                               ChessGame *board_) : ChessCommand(command_name, board_)
{
}

// --------------------------------------------------------------------------
CommandSetName::~CommandSetName()
{
}
