// --------------------------------------------------------------------------
// Filename: CommandQuit.cpp
//
//
//

// --------------------------------------------------------------------------

#include "CommandQuit.h"
#include "Game.h"
#include "WrongUsageCommandException.h"

#include <iostream>

// --------------------------------------------------------------------------

const std::string CommandQuit::GOOD_BYE_TEXT = "Bye!";

// --------------------------------------------------------------------------
void CommandQuit::execute(std::vector<std::string> &params)
{
  if (!params.size() != 1)
  {
    throw Sep::WrongUsageCommandException();
  }

  std::cout << GOOD_BYE_TEXT << std::endl;
  board_->setGameRuns(false);
}

// --------------------------------------------------------------------------
CommandQuit::CommandQuit(const string &command_name,
                         Game *board_) : Command(command_name,
                                                 board_)
{
}

// --------------------------------------------------------------------------
CommandQuit::~CommandQuit()
{
}
