// --------------------------------------------------------------------------
// Filename: CommandSave.cpp
//
//
//

// --------------------------------------------------------------------------

#include "CanNotSaveException.h"
#include "ChessGame.h"
#include "CommandSave.h"
#include "Game.h"
#include "History.h"
#include "InternalErrorException.h"
#include "Player.h"
#include "SaveUsageException.h"
#include <iostream>

#include <ctime>
#include <fstream>
#include <string>

using std::cout;
using std::endl;
using std::string;

// --------------------------------------------------------------------------
const unsigned int CommandSave::MAXIMUM_LINE_LENGHT = 80;
const string CommandSave::META_END = "\"]\n";
const string CommandSave::META_STRINGS[] =
    {
        "[Event \"",
        "[Site \"",
        "[Date \"",
        "[Round \"",
        "[White \"",
        "[Black \"",
        "[Result \"",
        "Graz University of Technology, Austria"};

// --------------------------------------------------------------------------
void CommandSave::execute(std::vector<std::string> &params)
{
  if (params.size() != 1)
  {
    throw Sep::SaveUsageException();
  }

  std::ofstream output_file;
  output_file.open(params[0].c_str());

  if (!output_file.is_open())
  {
    throw Sep::CanNotSaveException(params[0]);
  }

  if (board_->getPlayers().size() != 2)
  {
    throw Sep::InternalErrorException();
  }

  if (board_->getPlayers()[0]->getColor() == WHITE)
  {
    output_file << META_STRINGS[0] << board_->getPlayers()[0]->getName() << " vs. "
                << board_->getPlayers()[1]->getName() << META_END;
  }
  else
  {
    output_file << META_STRINGS[0] << board_->getPlayers()[1]->getName() << " vs. "
                << board_->getPlayers()[0]->getName() << META_END;
  }

  output_file << META_STRINGS[1] << META_STRINGS[7] << META_END;

  time_t seconds_since_1990 = time(0);
  std::tm *current_time = std::localtime(&seconds_since_1990);

  output_file << META_STRINGS[2] << current_time->tm_year + 1900;

  if ((current_time->tm_mon + 1) < 10)
  {
    output_file << ".0" << current_time->tm_mon + 1;
  }
  else
  {
    output_file << "." << current_time->tm_mon + 1;
  }

  if ((current_time->tm_mday + 1) < 10)
  {
    output_file << ".0" << current_time->tm_mday << META_END;
  }
  else
  {
    output_file << "." << current_time->tm_mday << META_END;
  }

  output_file << META_STRINGS[3] << "1" << META_END;

  if (board_->getPlayers()[0]->getColor() == WHITE)
  {
    output_file << META_STRINGS[4] << board_->getPlayers()[0]->getName() << META_END;
    output_file << META_STRINGS[5] << board_->getPlayers()[1]->getName() << META_END;
  }
  else
  {
    output_file << META_STRINGS[5] << board_->getPlayers()[1]->getName() << META_END;
    output_file << META_STRINGS[4] << board_->getPlayers()[0]->getName() << META_END;
  }

  output_file << META_STRINGS[6] << board_->getGameHistory()->gameResultToString() << META_END;

  board_->getGameHistory()->historyToFileStream(output_file,
                                                MAXIMUM_LINE_LENGHT);
  output_file << "\n";

  output_file.close();

  cout << "Game saved.\n";
}

CommandSave::CommandSave(const string &command_name, ChessGame *board_) : ChessCommand(command_name, board_)
{
}

// --------------------------------------------------------------------------
CommandSave::~CommandSave()
{
}
