// --------------------------------------------------------------------------
// Filename: CommandDraw.h
// Description: Class representing the draw command
//
//

// --------------------------------------------------------------------------

#ifndef COMMANDDRAW_H_
#define COMMANDDRAW_H_

#include "ChessCommand.h"
#include <string>

using std::string;

// --------------------------------------------------------------------------
// CommandDraw Class
// represents the command echo
//
class CommandDraw : public ChessCommand
{
private:
  // ----------------------------------------------------------------------
  // private copy constructor
  CommandDraw(const CommandDraw &other);

  // ----------------------------------------------------------------------
  // Constant for the draw decline command
  static const string DECLINE;

  // ----------------------------------------------------------------------
  // Constant for text if a palyer suggest a draw
  static const string SUGGEST_DRAW;

  // ----------------------------------------------------------------------
  // Constant for text if the game ends because of a draw
  static const string GAME_END;

  // ----------------------------------------------------------------------
  // Constant for text if the draw offer is declined
  static const string DRAW_DECLINED;

public:
  // ----------------------------------------------------------------------
  // constructor
  CommandDraw(const std::string &command_name, ChessGame *board_);

  // ----------------------------------------------------------------------
  // executes the command draw, offerers a draw to the opponent
  //
  // @param board The board where action should be performed on
  // @param has to be 0 when the draw is offered or decline if denied
  // @return returns an error code
  void execute(std::vector<std::string> &params);

  // ----------------------------------------------------------------------
  // destructor
  virtual ~CommandDraw();
};

#endif /* COMMANDDRAW_H_ */
