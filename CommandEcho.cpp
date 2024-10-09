// --------------------------------------------------------------------------
// Filename: CommandEcho.cpp
//
//
//

// --------------------------------------------------------------------------

#include "CommandEcho.h"
#include "Game.h"
#include "GameFinishedException.h"
#include "WrongUsageCommandException.h"

#include <iostream>

// --------------------------------------------------------------------------
void CommandEcho::execute(std::vector<std::string> &params)
{
  // if (params.size() != 1)
  //{
  //   throw Sep::WrongUsageCommandException();
  // }
  if (board_->getGameFinished())
  {
    // this error is given out due to
    // the instruction (only the commands
    // history save view and quit are
    // possible after the game has finished
    throw Sep::GameFinishedException();
  }
  for (auto param : params)
  {
    std::cout << param << " - ";
  }
  std::cout << std::endl;
}
// --------------------------------------------------------------------------
CommandEcho::CommandEcho(const string &command_name, Game *board_) : Command(command_name, board_)
{
}

// --------------------------------------------------------------------------
CommandEcho::~CommandEcho()
{
}
