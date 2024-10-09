// --------------------------------------------------------------------------
// Filename: CommandBmb.cpp
//
//
//

// --------------------------------------------------------------------------

#include "ChessGame.h"
#include "CommandBomb.h"
#include "WrongUsageCommandException.h"

#include <iostream>
#include <typeinfo>
#include <vector>
#include <string>

#include "GameFinishedException.h"
#include "IncorrectStartLocationException.h"
#include "IncorrectTargetLocationException.h"
#include "UnansweredDrawException.h"

using std::cout;
using std::endl;
using std::string;
using std::vector;

CommandBomb::CommandBomb(std::string command_name,
                         ChessGame *board) : ChessCommand(command_name, board)
{
}
// --------------------------------------------------------------------------
CommandBomb::~CommandBomb()
{
}

// --------------------------------------------------------------------------
void CommandBomb::execute(std::vector<std::string> &params)
{
  Point destination;

  if (params.size() != 1)
  {
    throw Sep::WrongUsageCommandException();
  }

  if (board_->getGameFinished())
  {
    throw Sep::GameFinishedException();
  }
  if (board_->getDrawOffered())
  {
    throw Sep::UnansweredDrawException();
  }

  board_->getPointOnBoard(params[0][0], params[0][1], destination);

  if (!board_->isPointOnBoard(destination.x_coordinate_, destination.y_coordinate_))
  {
    throw(Sep::IncorrectTargetLocationException());
  }

  board_->bomb(destination);
}
