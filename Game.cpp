// --------------------------------------------------------------------------
// Game.cpp
//
//
//

// --------------------------------------------------------------------------

#include "Command.h"
#include "CommandEcho.h"
#include "CommandQuit.h"
#include "CommandStatus.h"
#include "CommandView.h"
#include "Game.h"
#include "OutOfMemoryException.h"
#include "OwnBaseException.h"
#include "Piece.h"
#include "Player.h"
#include "UnknownCommandException.h"

#include <iostream>
#include <vector>

// --------------------------------------------------------------------------

using std::cout;
using std::string;
using std::vector;

// --------------------------------------------------------------------------

const string Game::COMMAND_PROMPT = "sep> ";
const string Game::COMMAND_NAMES[] =
    {
        "echo", "view", "quit", "status"};

// --------------------------------------------------------------------------
Game::Game() : first_row_name_(0), first_column_name_(0), increase_row_char_(0),
               increase_column_char_(true), game_runs_(true), turn_(0), active_player_(0),
               game_finished_(false)
{
  bounds_.x_coordinate_ = 0;
  bounds_.y_coordinate_ = 0;
  try
  {
    possible_commands_.push_back(new CommandEcho(COMMAND_NAMES[0], this));
    possible_commands_.push_back(new CommandView(COMMAND_NAMES[1], this));
    possible_commands_.push_back(new CommandQuit(COMMAND_NAMES[2], this));
    possible_commands_.push_back(new CommandStatus(COMMAND_NAMES[3], this));
  }
  catch (std::bad_alloc &e)
  {
    for (size_t iterator = 0; iterator < possible_commands_.size();
         iterator++)
    {
      delete possible_commands_[iterator];
    }
    possible_commands_.clear();
    throw Sep::OutOfMemoryException();
  }
}

// --------------------------------------------------------------------------
Game::Game(Point bounds, int active_player, int turn, char first_row_name,
           char first_column_name, bool increase_row_char,
           bool increase_column_char) : first_row_name_(first_row_name),
                                        first_column_name_(first_column_name), increase_row_char_(increase_row_char),
                                        increase_column_char_(increase_column_char), game_runs_(true),
                                        bounds_(bounds), turn_(turn), active_player_(active_player),
                                        game_finished_(false)
{
  try
  {
    possible_commands_.push_back(new CommandEcho(COMMAND_NAMES[0], this));
    possible_commands_.push_back(new CommandView(COMMAND_NAMES[1], this));
    possible_commands_.push_back(new CommandQuit(COMMAND_NAMES[2], this));
    possible_commands_.push_back(new CommandStatus(COMMAND_NAMES[3], this));
  }
  catch (std::bad_alloc &e)
  {
    for (size_t iterator = 0; iterator < possible_commands_.size();
         iterator++)
    {
      delete possible_commands_[iterator];
    }
    possible_commands_.clear();
    throw Sep::OutOfMemoryException();
  }
}

// --------------------------------------------------------------------------
Game::~Game()
{
  for (size_t iterator = 0; iterator < possible_commands_.size();
       iterator++)
  {
    delete possible_commands_[iterator];
  }
  for (size_t iterator = 0; iterator < players_.size();
       iterator++)
  {
    delete players_[iterator];
  }
  for (size_t iterator = 0; iterator < pieces_.size();
       iterator++)
  {
    delete pieces_[iterator];
  }
  possible_commands_.clear();
  players_.clear();
  pieces_.clear();
}

// --------------------------------------------------------------------------
void Game::addPlayer(Player *player)
{
  players_.push_back(player);
}

// --------------------------------------------------------------------------
void Game::addPiece(Piece *piece)
{
  pieces_.push_back(piece);
}

// --------------------------------------------------------------------------
void Game::removePiece(Piece *piece)
{
  for (size_t iterator = 0; iterator < pieces_.size(); iterator++)
  {
    if (pieces_[iterator] == piece)
    {
      delete pieces_[iterator];
      pieces_.erase(pieces_.begin() + iterator);
      break;
    }
  }
}

// --------------------------------------------------------------------------
string Game::getUserInput() const
{
  cout << COMMAND_PROMPT;
  string input_string;
  std::getline(std::cin, input_string);
  return input_string;
}

// --------------------------------------------------------------------------
string Game::getPointAsString(Point point) const
{
  string output_string = "00";
  char row_char;
  char column_char;

  if (increase_column_char_)
  {
    column_char = first_column_name_ + point.x_coordinate_;
  }
  else
  {
    column_char = first_column_name_ - point.x_coordinate_;
  }
  if (increase_row_char_)
  {
    row_char = first_row_name_ + point.y_coordinate_;
  }
  else
  {
    row_char = first_row_name_ - point.y_coordinate_;
  }

  output_string[0] = column_char;
  output_string[1] = row_char;

  return output_string;
}

// --------------------------------------------------------------------------
void Game::convertToLowerCase(string &input_string) const
{
  for (unsigned int iterator = 0; iterator < input_string.size(); iterator++)
  {
    if (input_string[iterator] >= 'A' && input_string[iterator] <= 'Z')
    {
      input_string[iterator] += ('a' - 'A');
    }
  }
}

// --------------------------------------------------------------------------
vector<string> Game::tokenizeCommandString(const string &command_string) const
{
  vector<string> tokens;
  size_t iterator = 0;

  while (iterator < command_string.size())
  {
    size_t next_space = command_string.find_first_of(" ", iterator);
    if (next_space == string::npos)
    {
      // The last token has been found => copy it onto the vector and
      // go home
      string sub_string = command_string.substr(iterator);
      if (sub_string != " " && !sub_string.empty())
      {
        tokens.push_back(sub_string);
      }
      break;
    }
    else
    {
      string sub_string = command_string.substr(iterator, next_space -
                                                              iterator);
      if (sub_string != " " && !sub_string.empty())
      {
        tokens.push_back(sub_string);
      }
      iterator = next_space + 1;
    }
  }
  return tokens;
}

// --------------------------------------------------------------------------
void Game::interpretCommandString(const string &command_string)
{
  vector<string> tokens = tokenizeCommandString(command_string);
  if (tokens.size() == 0)
  {
    return;
  }

  convertToLowerCase(tokens[0]);

  bool command_found = false;
  for (unsigned int iterator = 0; iterator < possible_commands_.size();
       iterator++)
  {
    if (possible_commands_[iterator]) // check for null-pointer
    {
      // if(called command equals one of the stored commands)
      if (tokens[0] == possible_commands_[iterator]->getName())
      {
        tokens.erase(tokens.begin());
        // call the corresponding command
        command_found = true;
        possible_commands_[iterator]->execute(tokens);
        break; // go home and return status
      }
    }
  }
  if (!command_found)
  {
    throw Sep::UnknownCommandException();
  }
}

// --------------------------------------------------------------------------
void Game::run()
{
  while (game_runs_)
  {
    try
    {
      interpretCommandString(getUserInput());
    }
    catch (Sep::OwnBaseException &e)
    {
      std::cout << e.what();
    }
  }
}

// --------------------------------------------------------------------------
void Game::setGameRuns(bool value)
{
  game_runs_ = value;
}

// --------------------------------------------------------------------------
string Game::getCurrentPlayerName()
{
  if (players_.size() <= active_player_)
  {
    return "";
  }
  else
  {
    return players_[active_player_]->getFullName();
  }
}

// --------------------------------------------------------------------------

char Game::getFirstRowName()
{
  return first_row_name_;
}

// --------------------------------------------------------------------------
char Game::getFirstColumnName()
{
  return first_column_name_;
}

// --------------------------------------------------------------------------
bool Game::getIncreaseRowChar()
{
  return increase_row_char_;
}

// --------------------------------------------------------------------------
bool Game::getIncreaseColumnChar()
{
  return increase_column_char_;
}

// --------------------------------------------------------------------------
Point Game::getBounds()
{
  return bounds_;
}

// --------------------------------------------------------------------------
vector<Player *> Game::getPlayers()
{
  return players_;
}

// --------------------------------------------------------------------------
int Game::getActivePlayer() const
{
  return active_player_;
}

// --------------------------------------------------------------------------
Player *Game::getCurrentPlayer() const
{
  return players_[active_player_];
}

// --------------------------------------------------------------------------
void Game::addPossibleCommand(Command *command)
{
  possible_commands_.push_back(command);
}

// --------------------------------------------------------------------------
bool Game::isPointOnBoard(int x, int y) const
{
  if ((x >= 0) && (x < bounds_.x_coordinate_) &&
      (y >= 0) && (y < bounds_.y_coordinate_))
  {
    return true;
  }
  else
  {
    return false;
  }
}

// --------------------------------------------------------------------------
bool Game::isPointOnBoard(Point &point) const
{
  if ((point.x_coordinate_ >= 0) &&
      (point.x_coordinate_ < bounds_.x_coordinate_) &&
      (point.y_coordinate_ >= 0) &&
      (point.y_coordinate_ < bounds_.y_coordinate_))
  {
    return true;
  }
  else
  {
    return false;
  }
}

// --------------------------------------------------------------------------
void Game::getPointOnBoard(char x, char y, Point &point)
{
  point.x_coordinate_ =
      relativeCharacterPosition(x,
                                this->getFirstColumnName(),
                                this->getIncreaseColumnChar());
  point.y_coordinate_ =
      relativeCharacterPosition(y,
                                this->getFirstRowName(),
                                this->getIncreaseRowChar());
}

// --------------------------------------------------------------------------
int Game::relativeCharacterPosition(char in_row_char,
                                    char first_row_char,
                                    bool increase_row_char)
{
  if (increase_row_char)
  {
    return in_row_char - first_row_char;
  }
  else
  {
    return first_row_char - in_row_char;
  }
}

// --------------------------------------------------------------------------
Piece *Game::getPieceOnPoint(int x, int y) const
{
  for (size_t piece_iterator = 0;
       piece_iterator < pieces_.size();
       piece_iterator++)
  {
    Piece *current_piece = pieces_[piece_iterator];
    if (current_piece->getX() == x && current_piece->getY() == y)
    {
      return current_piece;
    }
  }
  return NULL;
}

// --------------------------------------------------------------------------
std::vector<Piece *> Game::getPieces() const
{
  return pieces_;
}

// --------------------------------------------------------------------------
bool Game::getGameFinished()
{
  return game_finished_;
}

// --------------------------------------------------------------------------
int Game::getTurn()
{
  return turn_;
}

// --------------------------------------------------------------------------
vector<Command *> &Game::getPossibleCommands()
{
  return possible_commands_;
}
