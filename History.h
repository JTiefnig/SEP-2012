// --------------------------------------------------------------------------
// / Filename: History.h
// / Description: Class representing an action for a game
// / Created: 08.03.2012
// / Last change: 13.08.2011
// --------------------------------------------------------------------------

#ifndef HISTORY_H_INCLUDED
#define HISTORY_H_INCLUDED

#include "ChessGame.h"
#include <vector>

class ofstream;
using std::vector;

class History
{
private:
  // ----------------------------------------------------------------------
  // The collection of all moves which has be done so far
  //
  vector<Move> moves_;

  // ----------------------------------------------------------------------
  // a pointer to the game, the history refers to
  //
  ChessGame *board_;

  // ----------------------------------------------------------------------
  // Game result file output string when black wins
  //
  static const std::string BLACK_WINS;
  // ----------------------------------------------------------------------
  // Game result file output string when white wins
  //
  static const std::string WHITE_WINS;
  // ----------------------------------------------------------------------
  // Game result file output string when the game has ended in a draw
  //
  static const std::string DRAW;
  // ----------------------------------------------------------------------
  // Game result file output string when the game does not has a restult so
  // far
  //
  static const string NO_RESULT;

  // ----------------------------------------------------------------------
  // String for seperation of inexer and content in history file output
  //
  static const string STOP_AND_BLANK;

  // ----------------------------------------------------------------------
  // String for seperation
  //
  static const string BLANK;

  // ----------------------------------------------------------------------
  // String which defines the end of line in file output
  //
  static const std::string NEW_LINE_IN_FILE;

  // ----------------------------------------------------------------------
  // Thakes an index of a listed move and returns a string which represents
  // this move
  //
  // @param int index of the move
  //
  // @return string representing the move in SEP notation
  //
  std::string moveToString(int index) const;

public:
  // ----------------------------------------------------------------------
  // Constuctor of History
  //
  // @param pointer on Chessgame, the history should refer on
  //
  //
  History(ChessGame *board);

  // ----------------------------------------------------------------------
  // Destuctor of History
  //
  ~History();

  // ----------------------------------------------------------------------
  // This method adds an move to the move collection of History
  //
  // @param move to be added to collection
  //
  //
  void addMove(Move move);

  // ----------------------------------------------------------------------
  // This method writes the entire history to a filestream
  //
  // @param reference to the filestream
  // @param maximum linelenght the histroyoutput should have
  //
  //
  void historyToFileStream(std::ofstream &, unsigned int max_line_lenght);

  // ----------------------------------------------------------------------
  // Prints the entire histroy
  //
  //
  void printHistory() const;

  // ----------------------------------------------------------------------
  // Converts result of the game in PGN-notation
  //
  // @return string representing the result of the game in PGN-notation
  //
  const string gameResultToString() const;
};

#endif // HISTORY_H_INCLUDED
