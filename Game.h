// --------------------------------------------------------------------------
// Game.h
// Description: Class representing a two dimensional board game
//
//
//

// --------------------------------------------------------------------------
//

#ifndef GAME_H_
#define GAME_H_

#include <string>
#include <vector>

class Player;
class Piece;
class Command;
class Piece;

using std::string;
using std::vector;

typedef struct _Point_ // Position starting with 0/0
{
  int x_coordinate_;
  int y_coordinate_;
} Point;

// --------------------------------------------------------------------------
// Game Class
// represents any two-dimensional board game, which is based on rows and columns
// the
class Game
{
private:
  // ----------------------------------------------------------------------
  // Character representing the first row identifier
  //
  char first_row_name_;

  // ----------------------------------------------------------------------
  // Character representing the first column identifier
  //
  char first_column_name_;

  // ----------------------------------------------------------------------
  //
  //
  bool increase_row_char_;

  // ------------------------------------------------------ ----------------
  //
  //
  bool increase_column_char_;

  // ----------------------------------------------------------------------
  // As long as game_runs_ is true the game method run() will keep on working
  // else it stops the game
  //
  bool game_runs_;

  // ----------------------------------------------------------------------
  // constants for the user interface
  //
  static const string COMMAND_PROMPT;
  static const string COMMAND_NAMES[];

  // ----------------------------------------------------------------------
  // reads the user input from std::cin
  //
  // @return returns the user input
  string getUserInput() const;

protected:
  // ----------------------------------------------------------------------
  // bounds is an X-Y koordinate which represents the maximum game board range
  //
  Point bounds_;

  // ----------------------------------------------------------------------
  // Represents the current move
  //
  int turn_;

  // ----------------------------------------------------------------------
  // Index of the active player
  //
  unsigned int active_player_;

  // ----------------------------------------------------------------------
  // Vector of possible commands, which the user could make
  //
  vector<Command *> possible_commands_;

  // ----------------------------------------------------------------------
  // Piece objects array, representing the pieces on the game board
  //
  vector<Piece *> pieces_;
  // ----------------------------------------------------------------------
  // Player objects array, representing the players on the game board
  //
  vector<Player *> players_;

  // ----------------------------------------------------------------------
  // Seperates a string into several strings, being seperated by spaces.
  // Multiple spaces will be deleted and ignored
  //
  // @param command_string this string gets split up
  // @return std::vector of strings, containing the tokens
  //
  vector<string> tokenizeCommandString(const string &command_string) const;

  // ----------------------------------------------------------------------
  // Takes user input and executes the corresponding Command when found
  //
  // @param command_string is the user input
  //
  // @return returns SUCCESS or error code
  //
  virtual void interpretCommandString(const string &command_string);

  bool game_finished_;

public:
  // ----------------------------------------------------------------------
  // Constructor
  //
  Game();

  Player *getCurrentPlayer() const;
  // ----------------------------------------------------------------------
  // copy constructor
  //
  Game(const Game *);

  // ----------------------------------------------------------------------
  // Constructor
  //
  Game(Point bounds, int active_player, int turn, char first_row_name,
       char first_column_name, bool increase_row_char,
       bool increase_column_char);

  // ----------------------------------------------------------------------
  // Destructor
  //
  virtual ~Game();

  // ----------------------------------------------------------------------
  // Adds an new Player to the game
  //
  // @param player this player is added to the game
  //
  void addPlayer(Player *player);

  // ----------------------------------------------------------------------
  // Adds a new gaming piece to the game
  //
  // @param piece  This gaming piece will be added to the game
  //
  void addPiece(Piece *piece);

  // ----------------------------------------------------------------------
  // removes a gaming piece from the game
  //
  // @param piece  This gaming piece will be removed from the game
  //
  void removePiece(Piece *piece);

  // ----------------------------------------------------------------------
  // Runs the game in an endless loop that can only be stopped by setting
  // game_runs_ to false
  //
  void run();

  // ----------------------------------------------------------------------
  // Sets the value of game_runs_. Set to false to stop the endless loop of
  // run()
  //
  // @param value to be thegiven to game_runs_
  //
  void setGameRuns(bool value);

  // ----------------------------------------------------------------------
  // gets the full name (incl. color) of the current player
  //
  // @return returns the name of the current player
  //
  string getCurrentPlayerName();

  // ----------------------------------------------------------------------
  // Gets the first row name
  //
  // @return returns the first character of the row
  //
  char getFirstRowName();

  // ----------------------------------------------------------------------
  // Gets the first column name
  //
  // @return returns the first number of the columns
  //
  char getFirstColumnName();

  // ----------------------------------------------------------------------
  // if true the row nummeration increases, else it decreases
  //
  // @return returns the boolean value of Increase_Row_Char
  //
  bool getIncreaseRowChar();

  // ----------------------------------------------------------------------
  // if true the column numberation increases, else it decreases
  //
  // @return returns the boolean value of Increase_column_Char
  //
  bool getIncreaseColumnChar();

  // ----------------------------------------------------------------------
  // converts a point position to a string for the output
  //
  // @param point this point will be given out as string
  //
  // @return returns the point as string zb 0,0 = a1
  //
  string getPointAsString(Point point) const;

  // ----------------------------------------------------------------------
  // gets the X-Y coordinate which represents the maximum
  // game board range
  //
  // @return returns a Point, containing the bounds as x and y coordinate
  //
  Point getBounds();

  // ----------------------------------------------------------------------
  // getter method for the player vector
  //
  // @return returns the player vector
  //
  vector<Player *> getPlayers();

  // ----------------------------------------------------------------------
  // getter method for the pieces vector
  //
  // @return returns the pieces vector
  //
  std::vector<Piece *> getPieces() const;

  // ----------------------------------------------------------------------
  // determines the player which is now on the turn
  //
  // @return returns the current active player
  //
  int getActivePlayer() const;

  // ----------------------------------------------------------------------
  // adds a command to the game
  //
  // @param command this command will be added to the game
  //
  void addPossibleCommand(Command *command);

  // ----------------------------------------------------------------------
  // determines if the point defined by x and y is on the board
  //
  // @param x x coordinate of the point
  // @param y y coordinate of the point
  //
  // @return returns true if the point is on the board
  //
  bool isPointOnBoard(int x, int y) const;

  // ----------------------------------------------------------------------
  // converts x and y coordinate to a struct point
  //
  // @param x x coordinate of the point
  // @param y y coordinate of the point
  // @param point this is the point which gets overwritten by the new point
  //
  void getPointOnBoard(char x, char y, Point &point);

  // ----------------------------------------------------------------------
  // determines if the point defined by x and y is on the board
  //
  // @param x x coordinate of the point
  // @param y y coordinate of the point
  //
  // @return returns true if the point is on the board
  //
  Piece *getPieceOnPoint(int x, int y) const;

  // ----------------------------------------------------------------------
  // checks if the point is on the board
  //
  // @param point which get checked if it is on the board
  //
  // @return returns true if the point is on the board
  //
  bool isPointOnBoard(Point &point) const;

  // ----------------------------------------------------------------------
  // virtual method that should change the active player attribute to the
  // next player
  //
  virtual void nextPlayer() = 0;

  // ----------------------------------------------------------------------
  // getter method for the game finished attribute
  //
  // @return returns true if the game has finished
  //
  bool getGameFinished();

  // ----------------------------------------------------------------------
  // getter method for the turn attribute
  //
  // @return returns the current turn
  //
  int getTurn();

  // ----------------------------------------------------------------------
  // getter method for the commands
  //
  // @return returns the vector of the commands in the game
  //
  vector<Command *> &getPossibleCommands();

protected:
  // ----------------------------------------------------------------------
  // finds the row position of the character to find
  //
  // @param character_to_find this is the row identifier which will be
  // converted to a coordinate
  // @param first_row_char first row identifier
  // @param increase_row_char defines if the row character identiferer
  // increases
  //
  // @return returns the y coordinate of the row character
  //
  int relativeCharacterPosition(char character_to_find,
                                char first_row_char,
                                bool increase_row_char);

  // ----------------------------------------------------------------------
  // converts a string to lower case
  //
  // @param input_string this is the string which is going to be converted,
  // the original string will be overwritten
  void convertToLowerCase(string &input_string) const;
};

#endif // GAME_H_
