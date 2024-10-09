// --------------------------------------------------------------------------
// Filename: CommandView.cpp
//
//
//

// --------------------------------------------------------------------------

#include "CommandView.h"
#include "Game.h"
#include "Piece.h"
#include "WrongUsageCommandException.h"

#include <iostream>

// --------------------------------------------------------------------------

using std::cout;
using std::endl;
using std::string;

// --------------------------------------------------------------------------
const string CommandView::HEADER_LINE = "-+";
const string CommandView::SEPERATING_CHAR = "|";
const string CommandView::BLANK_CHAR = " ";

// --------------------------------------------------------------------------
void CommandView::execute(std::vector<string> &params)
{
  if (!params.empty())
  {
    throw Sep::WrongUsageCommandException();
  }

  cout << BLANK_CHAR << SEPERATING_CHAR;
  for (int column_iterator = 0;
       column_iterator < board_->getBounds().x_coordinate_; column_iterator++)
  {
    if (board_->getIncreaseColumnChar())
    {
      // static_cast<char> => makes cout output a character
      cout << static_cast<char>(board_->getFirstColumnName() +
                                column_iterator)
           << SEPERATING_CHAR;
    }
    else
    {
      // static_cast<char> => makes cout output a character
      cout << static_cast<char>(board_->getFirstColumnName() -
                                column_iterator)
           << SEPERATING_CHAR;
    }
  }
  cout << BLANK_CHAR << endl;

  for (int column_iterator = 0;
       column_iterator < board_->getBounds().x_coordinate_ + 1;
       column_iterator++)
  {
    cout << HEADER_LINE;
  }
  cout << BLANK_CHAR << endl;

  for (int row_iterator = 0;
       row_iterator < board_->getBounds().y_coordinate_; row_iterator++)
  {
    if (board_->getIncreaseRowChar())
    {
      // static_cast<char> => makes cout output a character
      cout << static_cast<char>(board_->getFirstRowName() +
                                row_iterator)
           << SEPERATING_CHAR;
    }
    else
    {
      // static_cast<char> => makes cout output a character
      cout << static_cast<char>(board_->getFirstRowName() -
                                row_iterator)
           << SEPERATING_CHAR;
    }

    for (int column_iterator = 0;
         column_iterator < board_->getBounds().x_coordinate_; column_iterator++)
    {
      Piece *piece_on_current_point = board_->getPieceOnPoint(column_iterator,
                                                              row_iterator);
      if (piece_on_current_point == NULL)
      {
        cout << BLANK_CHAR << SEPERATING_CHAR;
      }
      else
      {
        cout << piece_on_current_point->toString()
             << SEPERATING_CHAR;
      }
    }
    cout << BLANK_CHAR << endl;

    for (int column_iterator = 0;
         column_iterator < board_->getBounds().x_coordinate_ + 1;
         column_iterator++)
    {
      cout << HEADER_LINE;
    }
    cout << BLANK_CHAR << endl;
  }
}

// --------------------------------------------------------------------------
CommandView::CommandView(const string &command_name, Game *board_) : Command(command_name, board_)
{
}

// --------------------------------------------------------------------------
CommandView::~CommandView()
{
}
