// --------------------------------------------------------------------------
// Filename: CommandDraw.cpp
//
//
//

// --------------------------------------------------------------------------

#include "ChessGame.h"
#include "CommandDraw.h"

#include <iostream>

#include "GameFinishedException.h"
#include "NoDrawOfferedException.h"
#include "UsageDrawException.h"
#include "UsageDrawException.h"

const string CommandDraw::DECLINE = "decline";
const string CommandDraw::SUGGEST_DRAW = " suggests a draw.\n";
const string CommandDraw::GAME_END = "The game ends in a draw.\n";
const string CommandDraw::DRAW_DECLINED = " declined the draw offer.\n";

// --------------------------------------------------------------------------
void CommandDraw::execute(std::vector<std::string> &params)
{
  if (board_->getGameFinished())
  {
    throw Sep::GameFinishedException();
  }
  // check for wrong usage (to many or wrong params)
  if ((params.size() == 1 && params[0] != DECLINE) || params.size() > 1)
  {
    throw Sep::UsageDrawException();
  }
  // check if the draw declinme command was used right
  if (params.size() == 1 && !board_->getDrawOffered())
  {
    throw Sep::NoDrawOfferedException();
  }

  if (board_->getDrawOffered() == false)
  {
    board_->setDrawOffered(true);
    std::cout << board_->getCurrentPlayerName() << SUGGEST_DRAW;
  }
  else if ((board_->getDrawOffered() == true) && !params.size())
  {
    // set the game to finished and write a message
    board_->setGameFinished(true);
    std::cout << GAME_END;
  }
  else if (board_->getDrawOffered() == true && params[0] == DECLINE)
  {
    board_->setDrawOffered(false);
    std::cout << board_->getCurrentPlayerName() << DRAW_DECLINED;
  }
  else
  {
    throw Sep::UsageDrawException();
  }
  board_->nextPlayer();
}
// --------------------------------------------------------------------------
CommandDraw::CommandDraw(const std::string &command_name, ChessGame *board_) : ChessCommand(command_name, board_)
{
}

// --------------------------------------------------------------------------
CommandDraw::~CommandDraw()
{
}
