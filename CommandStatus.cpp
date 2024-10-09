// --------------------------------------------------------------------------
// Filename: CommandStatus.cpp
//
//
//

// --------------------------------------------------------------------------

#include "CommandStatus.h"
#include "Game.h"
#include "GameFinishedException.h"
#include "Player.h"
#include "WrongUsageCommandException.h"

#include <iostream>

// --------------------------------------------------------------------------
void CommandStatus::execute(std::vector<std::string> &params)
{
  if (!params.empty())
  {
    throw Sep::WrongUsageCommandException();
  }
  if (board_->getGameFinished())
  {
    throw Sep::GameFinishedException();
  }
  std::cout << "current player: " << *(board_->getCurrentPlayer()) << std::endl;
}

// --------------------------------------------------------------------------
CommandStatus::CommandStatus(const string &command_name,
                             Game *board_) : Command(command_name,
                                                     board_)
{
}

// --------------------------------------------------------------------------
CommandStatus::~CommandStatus()
{
}
