// --------------------------------------------------------------------------
// Filename: History.cpp
//
//
//

// --------------------------------------------------------------------------

#include "ChessCommand.h"
#include "ChessGame.h"
#include "History.h"
#include "Player.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

const std::string History::BLACK_WINS = "0-1";
const std::string History::WHITE_WINS = "1-0";
const std::string History::DRAW = "1/2-1/2";
const std::string History::NO_RESULT = "*";
const std::string History::STOP_AND_BLANK = ". ";
const std::string History::BLANK = " ";
const std::string History::NEW_LINE_IN_FILE = "\n";

// --------------------------------------------------------------------------
History::History(ChessGame *board) : board_(board)
{
}

// --------------------------------------------------------------------------
History::~History()
{
  moves_.clear();
}

// --------------------------------------------------------------------------
void History::addMove(Move move)
{
  moves_.push_back(move);
}

// --------------------------------------------------------------------------
void History::printHistory() const
{
  int movenumber = 1;

  for (unsigned int iterator = 0; iterator < moves_.size(); iterator += 2)
  {
    cout << movenumber << STOP_AND_BLANK;
    movenumber++;
    cout << board_->getMoveToString(moves_[iterator]);
    if ((iterator + 1) < moves_.size())
    {
      cout << BLANK << board_->getMoveToString(moves_[iterator + 1]);
    }

    cout << endl;
  }
}

// --------------------------------------------------------------------------
void History::historyToFileStream(std::ofstream &os,
                                  unsigned int max_line_length)
{
  int move_number = 1;

  unsigned int line_length_couter = 0;

  for (unsigned int iterator = 0; iterator < moves_.size(); iterator += 2)
  {
    string move_string;

    std::stringstream ss; // need stringstream to convert movecount
    ss << move_number;
    move_string = ss.str();

    move_string += STOP_AND_BLANK; // add seperation between index and content
    move_number++;

    move_string += board_->getMoveToString(moves_[iterator]);

    if ((iterator + 1) < moves_.size())
    {
      move_string += BLANK;
      move_string += board_->getMoveToString(moves_[iterator + 1]);
    }
    // tests whether the existent line plus the new movestring is
    // longer than the defined maximum line lenght
    if ((line_length_couter + move_string.size()) > max_line_length &&
        line_length_couter)
    {
      os << NEW_LINE_IN_FILE;
      line_length_couter = 0;
    }
    if (move_number > 1 && line_length_couter != 0)
    {
      os << BLANK;
      line_length_couter++;
    }
    os << move_string;
    line_length_couter += move_string.size();
  }
}

// --------------------------------------------------------------------------
const string History::gameResultToString() const
{
  if (moves_.size())
  {

    Move last_move = moves_[moves_.size() - 1];

    if (last_move.check_ && last_move.finished_)
    {
      if (board_->getCurrentPlayer()->getColor() == BLACK)
      {
        return BLACK_WINS;
      }
      else
      {
        return WHITE_WINS;
      }
    }
  }
  if (board_->getGameFinished())
  {
    return DRAW;
  }

  return NO_RESULT;
}
