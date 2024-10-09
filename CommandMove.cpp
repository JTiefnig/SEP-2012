#include "ChessGame.h"
#include "CommandMove.h"
#include "History.h"
#include "Piece.h"
#include "PieceKing.h"
#include "Player.h"

#include <iostream>
#include <typeinfo>
#include <vector>

#include "GameFinishedException.h"
#include "IncorrectStartLocationException.h"
#include "IncorrectTargetLocationException.h"
#include "MoveUsageException.h"
#include "UnansweredDrawException.h"

using std::vector;
using std::string;
using std::cout;
using std::endl;


// --------------------------------------------------------------------------
CommandMove::CommandMove(std::string command_name,
                         ChessGame*  board) : ChessCommand(command_name, board)
{
}
// --------------------------------------------------------------------------
CommandMove::~CommandMove()
{
}

// --------------------------------------------------------------------------
void CommandMove::convertToPoints(vector<std::string>& params,
                                  Point&               starting_point,
                                  Point&               end_point)
{
  if (params[0].size() < 2 || params[1].size() < 2)
  {
    throw Sep::MoveUsageException();
  }
  if (!(( params[0][0] >= 'A' && params[0][0] <= 'Z' ) ||
        (( params[0][0] >= 'a' && params[0][0] <= 'z' ) &&
         ( params[1][0] >= 'A' && params[1][0] <= 'Z' )) ||
        ( params[1][0] >= 'a' && params[1][0] <= 'z' )))
  {
    throw Sep::MoveUsageException();
  }
  if (!( params[0][1] >= '0' && params[0][1] <= '9' &&
         params[1][1] >= '0' && params[1][1] <= '9' ))
  {
    throw Sep::MoveUsageException();
  }
  if (params[0].size() > 2)
  {
    throw ( Sep::IncorrectStartLocationException());
  }
  if (params[1].size() > 2)
  {
    throw ( Sep::IncorrectTargetLocationException());
  }

  board_->getPointOnBoard(params[0][0], params[0][1], starting_point);

  if (!board_->isPointOnBoard(starting_point.x_coordinate_,
                              starting_point.y_coordinate_))
  {
    throw ( Sep::IncorrectStartLocationException());
  }


  board_->getPointOnBoard(params[1][0], params[1][1], end_point);

  if (!board_->isPointOnBoard(end_point.x_coordinate_, end_point.y_coordinate_))
  {
    throw ( Sep::IncorrectTargetLocationException());
  }
}


// --------------------------------------------------------------------------
void CommandMove::execute(vector<std::string>& params)
{
  Point starting_point;
  Point end_point;

  if (params.size() != 2)
  {
    throw Sep::MoveUsageException();   // error message is given out before game
                                       // finished because we couldn't find a
                                       // proper instruction in the description
                                       // of ass3
  }

  // if the game is finished no move is possible
  if (board_->getGameFinished())        
  {
    throw Sep::GameFinishedException();
  }
  if (board_->getDrawOffered())
  {
    throw Sep::UnansweredDrawException();
  }
  convertToPoints(params, starting_point, end_point);

  board_->movePiece(starting_point, end_point);
}
