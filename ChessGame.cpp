// --------------------------------------------------------------------------
// ChessGame.cpp
//
//
//

// --------------------------------------------------------------------------

#include "ChessGame.h"
#include "CommandDraw.h"
#include "CommandHistory.h"
#include "CommandMove.h"
#include "CommandSave.h"
#include "CommandSetName.h"
#include "CommandBomb.h"
#include "History.h"
#include "Piece.h"
#include "Player.h"

#include "IncorrectStartLocationException.h"
#include "IncorrectTargetLocationException.h"
#include "InternalErrorException.h"
#include "InternalErrorException.h"
#include "NoOwnPieceAtLocationException.h"
#include "NoPieceAtLocationException.h"
#include "NoSacrificeException.h"
#include "OutOfMemoryException.h"
#include "OwnBaseException.h"
#include "OwnPieceOnTargetException.h"
#include "PieceBishop.h"
#include "PieceKing.h"
#include "PieceKnight.h"
#include "PieceOnWayException.h"
#include "PiecePawn.h"
#include "PieceQueen.h"
#include "PieceRook.h"
#include "SetupStringCorruptException.h"
#include "SetupStringInvalidException.h"
#include "TargetNotReachableException.h"
#include "UnknownCommandException.h"
#include "WrongUsageCommandException.h"

#include <iostream>
#include <string>
#include <typeinfo>
#include <vector>

using Sep::SetupStringCorruptException;
using Sep::SetupStringInvalidException;
using std::vector;

using std::cout;
using std::endl;

const Point ChessGame::CHESS_BOUNDS =
    {
        8, 8};
const char ChessGame::END_OF_ARGUMENT = '\0';
const std::string ChessGame::NEW_PIECE_QUESTION =
    "Which Piece instead of the pawn do you want?\n";
const std::string ChessGame::WRONG_ANSWER =
    "Please type the first character "
    "of the name of the piece you want(q,r,n,b).\n";
const std::string ChessGame::PLAYER_WINS = " wins!\n";
const std::string ChessGame::STALEMATE_MESSAGE =
    "Stalemate - the game ends in a draw.\n";

// --------------------------------------------------------------------------
ChessGame::ChessGame() : Game()
{
  createTemporaryBoard();
  game_history_ = new History(this);
}

// --------------------------------------------------------------------------
ChessGame::~ChessGame()
{
  for (int x_counter = 0; x_counter < bounds_.x_coordinate_; x_counter++)
  {
    delete[] temporary_board_[x_counter];
  }
  delete[] temporary_board_;
  delete game_history_;
}

// 8 and a hardcoded because its the chess rules
// --------------------------------------------------------------------------
ChessGame::ChessGame(int active_player, int turn, bool bonus) : Game(CHESS_BOUNDS, active_player, turn, '8', 'a', false, true),
                                                                draw_offered_(false), additional_rule_(bonus)
{
  try
  {
    createTemporaryBoard();
    addPossibleCommand(new CommandHistory("history", this));
    addPossibleCommand(new CommandMove("move", this));
    addPossibleCommand(new CommandSave("save", this));
    addPossibleCommand(new CommandDraw("draw", this));
    addPossibleCommand(new CommandSetName("setname", this));
    addPossibleCommand(new CommandBomb("bomb", this));
    game_history_ = new History(this);
  }
  catch (std::bad_alloc)
  {
    for (int x_counter = 0; x_counter < bounds_.x_coordinate_; x_counter++)
    {
      delete[] temporary_board_[x_counter];
    }
    delete[] temporary_board_;
    delete game_history_;
    throw Sep::OutOfMemoryException();
  }
}
// --------------------------------------------------------------------------
void ChessGame::createTemporaryBoard()
{
  try
  {
    temporary_board_ = (new Piece **[bounds_.x_coordinate_]);
  }
  catch (std::bad_alloc e)
  {
    throw Sep::OutOfMemoryException();
  }

  for (int x_counter = 0; x_counter < bounds_.x_coordinate_; x_counter++)
  {
    try
    {
      temporary_board_[x_counter] = new Piece *[bounds_.y_coordinate_];
    }
    catch (std::bad_alloc e)
    {
      for (int iterator = 0; iterator < x_counter; iterator++)
      {
        // delete all the columns that have already been allocated
        delete[] temporary_board_[iterator];
      }
      // delete the first dimension of the array
      delete[] temporary_board_;
      throw Sep::OutOfMemoryException();
    }
  }
  updateBoard();
}
// --------------------------------------------------------------------------
Player *ChessGame::getEnemy() const
{
  return players_[getActivePlayer() ^ 1]; // XOR to toggle player
}

// --------------------------------------------------------------------------
void ChessGame::movePiece(Point &start, Point &end)
{
  updateBoard();
  Player *player = getCurrentPlayer();
  Player *enemy = getEnemy();
  Piece *piece_to_move = getPieceOnPoint(start.x_coordinate_,
                                         start.y_coordinate_);

  if (!piece_to_move)
  {
    throw Sep::NoPieceAtLocationException();
  }
  else if (piece_to_move->getPlayer() != player)
  {
    throw Sep::NoOwnPieceAtLocationException();
  }
  else
  {
    // just move on...
  }

  Move move;
  move.piece_id_ = piece_to_move->toString();
  move.start_point_ = start;
  move.end_point_ = end;
  move.captured_ = false;
  move.move_error_ = piece_to_move->move_possible(end, temporary_board_);

  if (move.move_error_ == MOVE_SUCCESS ||
      move.move_error_ == ENPASSANTE ||
      move.move_error_ == MOVE_SUCCESS_TRANSFORMATION ||
      move.move_error_ == CAPTURED_TRANSFORMATION ||
      move.move_error_ == CAPTURED)
  {
    // move worked: now check whether we endanger our own king
    move_temporary(start, end);
    Point king_position = getTemporaryKingPosition(player);
    // >= 0 checks for existance
    if (king_position.x_coordinate_ >= 0 && canBeAttacked(king_position, enemy))
    {
      throw Sep::NoSacrificeException();
    }
  }

  switch (move.move_error_)
  {
  case MOVE_SUCCESS:
  {
    piece_to_move->moveToPosition(end);
    setWinStatus(move);
    move.piece_id_ = piece_to_move->toString();
    printMoveMessage(move);
    game_history_->addMove(move);
    break;
  }
  case CAPTURED:
  {
    move.captured_ = true;
    Piece *captured_piece = getPieceOnPoint(end.x_coordinate_,
                                            end.y_coordinate_);
    removePiece(captured_piece);
    piece_to_move->moveToPosition(end);
    setWinStatus(move);
    printMoveMessage(move);
    game_history_->addMove(move);
    break;
  }
  case ENPASSANTE:
  {
    move.captured_ = true;
    // strange but right ;)
    Piece *captured_piece = getPieceOnPoint(end.x_coordinate_,
                                            start.y_coordinate_);
    removePiece(captured_piece);
    removePiece(captured_piece);
    temporary_board_[end.x_coordinate_][start.y_coordinate_] = 0;
    piece_to_move->moveToPosition(end);

    setWinStatus(move);
    printMoveMessage(move);
    game_history_->addMove(move);
    break;
  }
  case ROCHADE:
  {
    Point rook_start;
    Point rook_end;
    rook_start.y_coordinate_ = start.y_coordinate_;
    rook_end.y_coordinate_ = start.y_coordinate_;
    if (end.x_coordinate_ > start.x_coordinate_) // rochade to the right
    {
      rook_start.x_coordinate_ = bounds_.x_coordinate_ - 1;
      rook_end.x_coordinate_ = start.x_coordinate_ + 1;
    }
    else // rochade to the left
    {
      rook_start.x_coordinate_ = 0;
      rook_end.x_coordinate_ = start.x_coordinate_ - 1;
    }
    if (canBeAttacked(start, enemy) || canBeAttacked(rook_end, enemy))
    {
      throw Sep::NoSacrificeException();
    }
    move_temporary(rook_start, rook_end);

    Piece *captured_piece = getPieceOnPoint(end.x_coordinate_,
                                            start.y_coordinate_);
    if (captured_piece)
    {
      move.captured_ = true;
    }
    removePiece(captured_piece);
    piece_to_move->moveToPosition(end);
    temporary_board_[rook_end.x_coordinate_][rook_end.y_coordinate_]->moveToPosition(rook_end);

    setWinStatus(move);
    printMoveMessage(move);
    game_history_->addMove(move);
    break;
  }

  case CAPTURED_TRANSFORMATION:
  {
    move.captured_ = true;

    Piece *new_piece = askWhichPiece(getCurrentPlayer(), end);
    // add the new queen before mate is checked
    temporary_board_[end.x_coordinate_][end.y_coordinate_] = new_piece;
    Piece *captured_piece = getPieceOnPoint(end.x_coordinate_,
                                            end.y_coordinate_);
    removePiece(captured_piece);
    removePiece(piece_to_move);
    addPiece(new_piece);
    move.piece_id_ = new_piece->toString();
    setWinStatus(move);
    printMoveMessage(move);
    game_history_->addMove(move);
    break;
  }
  case MOVE_SUCCESS_TRANSFORMATION:
  {
    Piece *new_piece = askWhichPiece(getCurrentPlayer(), end);
    // add the new queen before mate is checked
    temporary_board_[end.x_coordinate_][end.y_coordinate_] = new_piece;

    removePiece(piece_to_move);
    addPiece(new_piece);

    move.piece_id_ = new_piece->toString();
    setWinStatus(move);
    printMoveMessage(move);
    game_history_->addMove(move);
    break;
  }
  case TARGET_NOT_REACHABLE:
    throw Sep::TargetNotReachableException();

    break;
  case OWN_PIECE_AT_TARGET:
    throw Sep::OwnPieceOnTargetException();

    break;
  case PIECE_IN_THE_WAY:
    throw Sep::PieceOnWayException();
    break;
  case ERROR_OUT_OF_FIELD:
    throw Sep::TargetNotReachableException();
    break;
  }
  if (move.finished_)
  {
    setGameFinished(true);
  }
  nextPlayer();
}

void ChessGame::bomb(Point destination)
{
  if (!getCurrentPlayer()->hasBombed())
  {
    updateBoard();
    getCurrentPlayer()->setBombed();
    // Player* player = getCurrentPlayer();

    for (int x_count = -3; x_count <= 3; x_count++)
    {
      int endp = 3 - x_count;
      if (x_count < 0)
        endp = 3 + x_count;

      for (int y_count = -endp; y_count <= endp; y_count++)
      {
        int cx = destination.x_coordinate_ + x_count;
        int cy = destination.y_coordinate_ + y_count;
        if (isPointOnBoard(cx, cy))
        {
          if (temporary_board_[cx][cy])
          {
            if (typeid(*temporary_board_[cx][cy]) != typeid(PieceKing))
            {
              removePiece(temporary_board_[cx][cy]);
            }
          }
        }
      }
    }

    nextPlayer();
  }
}

// --------------------------------------------------------------------------
bool ChessGame::enemyMovePossible()
{
  Player *player = getCurrentPlayer();
  Player *enemy = getEnemy();
  Point start;
  Point end;

  // iterate over all enemy pieces to find one that can be moved
  for (size_t piece_iterator = 0;
       piece_iterator < pieces_.size();
       piece_iterator++)
  {
    Piece *piece_to_move = pieces_[piece_iterator];
    if (piece_to_move->getPlayer() != enemy)
    {
      continue; // throw out the pieces that do not belong to the enemy
    }
    // Take temporaryPosition instead of getPosition() because
    // by capturing something could have changed
    start = getTemporaryPosition(piece_to_move);
    if (start.x_coordinate_ < 0)
    {
      // Piece does not exist any more on temporary board
      continue;
    }
    // check every point on the board to find one spot where the piece could go
    for (int x = 0; x < bounds_.x_coordinate_; x++)
    {
      for (int y = 0; y < bounds_.y_coordinate_; y++)
      {
        end.x_coordinate_ = x;
        end.y_coordinate_ = y;
        int status = piece_to_move->move_possible(start, end, temporary_board_);
        if (status != CAPTURED && status != MOVE_SUCCESS && status != MOVE_SUCCESS_TRANSFORMATION && status != CAPTURED_TRANSFORMATION &&
            status != ENPASSANTE)
        {
          continue; // move is not possible try something else
        }

        move_temporary(start, end);
        Point enemy_king_position = getTemporaryKingPosition(enemy);
        // x > 0 checks for existance of king:
        // getTemporaryKing returns x=-1 upon failure
        if (enemy_king_position.x_coordinate_ >= 0 &&
            canBeAttacked(enemy_king_position, player))
        {
          undo_temporary_move(); // undo test move
          continue;
        }
        undo_temporary_move(); // undo test move
        // One piece was found that can be moved somewhere
        // without exposing the king
        return true;
      }
    }
  }

  return false;
}
// --------------------------------------------------------------------------
void ChessGame::printMoveMessage(Move &move)
{
  cout << getMoveToString(move) << std::endl;

  if (move.check_ && move.finished_)
  {
    cout << getCurrentPlayer()->getFullName() << PLAYER_WINS;
  }
  else if (move.finished_) // finished but no check
  {
    cout << STALEMATE_MESSAGE;
  }
}

string ChessGame::getMoveToString(Move move)
{
  string move_string = "";
  string piece_identifier = move.piece_id_;

  if (!piece_identifier[0])
  {
    throw Sep::InternalErrorException();
  }
  if (piece_identifier[0] >= 'a' && piece_identifier[0] <= 'z')
  {
    piece_identifier[0] -= ('a' - 'A');
  }
  if (piece_identifier == "P")
  {
    piece_identifier = "";
  }
  move_string += piece_identifier;
  move_string += getPointAsString(move.start_point_);
  if (move.captured_)
  {
    move_string += "x";
  }
  else
  {
    move_string += "-";
  }
  move_string += getPointAsString(move.end_point_);
  if (move.move_error_ == CAPTURED_TRANSFORMATION ||
      move.move_error_ == MOVE_SUCCESS_TRANSFORMATION)
  {
    move_string.erase(0, 1);
    move_string += "=";
    if (move.piece_id_[0] >= 'a' && move.piece_id_[0] <= 'z')
    {
      move_string += (move.piece_id_[0] - ('a' - 'A'));
    }
    else
    {
      move_string += move.piece_id_;
    }
  }
  if (move.check_)
  {
    move_string += "+";
    if (move.finished_)
    {
      move_string += "+";
    }
  }
  return move_string;
}

void ChessGame::setWinStatus(Move &move)
{
  Player *player = getCurrentPlayer();
  Player *enemy = getEnemy();
  Point enemy_king_position = getTemporaryKingPosition(enemy);

  // Defaults in case nothing happend
  move.check_ = false;
  move.finished_ = false;
  if (enemy_king_position.x_coordinate_ >= 0 &&
      canBeAttacked(enemy_king_position, player))
  {
    move.check_ = true;
    if (!enemyMovePossible())
    {
      move.finished_ = true;
    }
  }
  // can not be attacked but maybe no move either => Remis
  else if (!enemyMovePossible())
  {
    move.check_ = false;
    move.finished_ = true;
  }
  else // nothing special happened
  {
  }
}
// --------------------------------------------------------------------------
Point ChessGame::getTemporaryPosition(Piece *piece)
{
  Point piece_position;

  for (int x = 0; x < bounds_.x_coordinate_; x++)
  {
    for (int y = 0; y < bounds_.y_coordinate_; y++)
    {
      if (temporary_board_[x][y] == piece)
      {
        piece_position.x_coordinate_ = x;
        piece_position.y_coordinate_ = y;
        return piece_position;
      }
    }
  }
  piece_position.x_coordinate_ = -1;
  piece_position.y_coordinate_ = -1;

  return piece_position;
}

Point ChessGame::getTemporaryKingPosition(Player *player) const
{
  Point king_position;

  for (int x = 0; x < bounds_.x_coordinate_; x++)
  {
    for (int y = 0; y < bounds_.y_coordinate_; y++)
    {
      if (temporary_board_[x][y] != 0)
      {
        if (temporary_board_[x][y]->getPlayer() == player &&
            typeid(*temporary_board_[x][y]) == typeid(PieceKing))
        {
          king_position.x_coordinate_ = x;
          king_position.y_coordinate_ = y;
          return king_position;
        }
      }
    }
  }
  king_position.x_coordinate_ = -1;
  king_position.y_coordinate_ = -1;

  return king_position;
}

// --------------------------------------------------------------------------
void ChessGame::interpretCommandString(const string &command_string)
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
        try
        {
          possible_commands_[iterator]->execute(tokens);
        }
        catch (Sep::OwnBaseException &e)
        {
          std::cout << e.what();
        }
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
void ChessGame::nextPlayer()
{
  active_player_ ^= 1; // Toggle Players
  turn_++;
}

// --------------------------------------------------------------------------
Piece *ChessGame::createPieceFromArguments(char piece_id, Player *owner,
                                           Point piece_position)
{
  // change the piece_id to lower case
  if (piece_id >= 'A' && piece_id <= 'Z')
  {
    piece_id += ('a' - 'A');
  }

  Piece *new_piece_object = 0;
  switch (piece_id)
  {
  case 'n':
    new_piece_object = new PieceKnight(piece_position, this, owner);
    break;
  case 'k':
    new_piece_object = new PieceKing(piece_position, this, owner);
    break;
  case 'q':
    new_piece_object = new PieceQueen(piece_position, this, owner);
    break;
  case 'p':
    new_piece_object = new PiecePawn(piece_position, this, owner);
    break;
  case 'r':
    new_piece_object = new PieceRook(piece_position, this, owner);
    break;
  case 'b':
    new_piece_object = new PieceBishop(piece_position, this, owner);
    break;
  default:
    throw Sep::SetupStringInvalidException();
  }
  return new_piece_object;
}

// --------------------------------------------------------------------------
void ChessGame::createBoardFromArguments(const string args)
{
  int iterator = 0;

  // check for internal errors (wrong number of players)
  if (this->getPlayers().size() != 2)
  {
    throw Sep::InternalErrorException();
  }
  if (args.length() % 3 != 0)
  {
    throw Sep::SetupStringCorruptException();
  }

  while (args[iterator] != END_OF_ARGUMENT && args[iterator + 1] != END_OF_ARGUMENT &&
         args[iterator + 2] != END_OF_ARGUMENT)
  {
    Point piece_position;
    // get the position of the new piece
    this->getPointOnBoard(args[iterator + 1],
                          args[iterator + 2],
                          piece_position);
    Piece *new_piece_object = NULL;

    // check the position if it is on the board
    if (!this->isPointOnBoard(piece_position))
    {
      throw Sep::SetupStringInvalidException();
    }

    char piece_id = args[iterator];

    Player *owner = 0;
    // identify to which player the piece belongs to
    if (piece_id >= 'A' && piece_id <= 'Z')
    {
      owner = getPlayers()[0];
    }
    else if (piece_id >= 'a' && piece_id <= 'z')
    {
      owner = getPlayers()[1];
    }

    try
    {
      // get the new piece
      new_piece_object = this->createPieceFromArguments(piece_id,
                                                        owner, piece_position);
    }
    catch (std::bad_alloc &e)
    {
      throw Sep::OutOfMemoryException();
    }

    new_piece_object->setColor(owner->getColor());

    // check if already a piece on this position exists
    for (size_t iterator_pieces = 0; iterator_pieces < pieces_.size();
         iterator_pieces++)
    {
      if (pieces_[iterator_pieces]->getPosition().x_coordinate_ ==
              piece_position.x_coordinate_ &&
          pieces_[iterator_pieces]->getPosition().y_coordinate_ ==
              piece_position.y_coordinate_)
      {
        delete new_piece_object;
        throw Sep::SetupStringInvalidException();
      }
    }

    addPiece(new_piece_object);

    iterator += 3;
  }
}

// --------------------------------------------------------------------------
bool ChessGame::getDrawOffered()
{
  return draw_offered_;
}

// --------------------------------------------------------------------------
void ChessGame::setDrawOffered(bool input)
{
  draw_offered_ = input;
}

// --------------------------------------------------------------------------
void ChessGame::setGameFinished(bool input)
{
  game_finished_ = input;
}

void ChessGame::updateBoard()
{
  // clear the temporary board
  for (int length_counter = 0;
       length_counter < bounds_.x_coordinate_;
       length_counter++)
  {
    for (int width_counter = 0;
         width_counter < bounds_.y_coordinate_;
         width_counter++)
    {
      temporary_board_[length_counter][width_counter] = 0;
    }
  }

  // run through all pieces and place them on the board
  for (size_t piece_counter = 0; piece_counter < pieces_.size(); piece_counter++)
  {
    // write onto the field a pointer to the player to mark,
    // that some piece of him is standing there
    temporary_board_[pieces_[piece_counter]->getX()][pieces_[piece_counter]->getY()] =
        pieces_[piece_counter];
  }
}

void ChessGame::move_temporary(const Point &starting_point,
                               const Point &end_point)
{
  Move move;

  move.start_point_ = starting_point;
  move.end_point_ = end_point;

  // save the field where the piece will move to
  temporary_captured_.push_back(temporary_board_[end_point.x_coordinate_][end_point.y_coordinate_]);
  // save move_coordinates for redo
  temporary_moves_.push_back(move);

  temporary_board_[end_point.x_coordinate_][end_point.y_coordinate_] = temporary_board_[starting_point.x_coordinate_][starting_point.y_coordinate_];
  temporary_board_[starting_point.x_coordinate_][starting_point.y_coordinate_] = 0;
}

void ChessGame::undo_temporary_move()
{
  Move move = temporary_moves_.back();

  temporary_moves_.pop_back();

  Piece *original_end_piece = temporary_captured_.back();
  temporary_captured_.pop_back();

  temporary_board_[move.start_point_.x_coordinate_][move.start_point_.y_coordinate_] =
      temporary_board_[move.end_point_.x_coordinate_][move.end_point_.y_coordinate_];
  temporary_board_[move.end_point_.x_coordinate_]
                  // substitute back the original piece on end point
                  [move.end_point_.y_coordinate_] = original_end_piece;
}

// --------------------------------------------------------------------------
bool ChessGame::canBeAttacked(Point position, Player *attacker) const
{
  for (int x = 0; x < bounds_.x_coordinate_; x++)
  {
    for (int y = 0; y < bounds_.y_coordinate_; y++)
    {
      if (temporary_board_[x][y] && temporary_board_[x][y]->getPlayer() ==
                                        attacker)
      {
        Point start;
        start.x_coordinate_ = x;
        start.y_coordinate_ = y;
        int move_status = temporary_board_[x][y]->move_possible(
            start,
            position,
            temporary_board_);
        if (move_status == CAPTURED || move_status == MOVE_SUCCESS ||
            move_status == MOVE_SUCCESS_TRANSFORMATION || move_status == CAPTURED_TRANSFORMATION)
        {
          return true;
        }
      }
    }
  }
  return false;
}

// --------------------------------------------------------------------------
History *ChessGame::getGameHistory()
{
  return game_history_;
}

// --------------------------------------------------------------------------
bool ChessGame::getAdditionalRules()
{
  return additional_rule_;
}

// --------------------------------------------------------------------------
Piece *ChessGame::askWhichPiece(Player *owner, Point position)
{
  std::cout << NEW_PIECE_QUESTION;

  std::string answer;
  Piece *new_piece = 0;
  bool right_anwser = false;
  while (!right_anwser)
  {
    std::getline(std::cin, answer);

    // no transformation in pawn or king allowed!
    if (answer.size() != 1 || answer[0] == 'p' || answer[0] == 'P' ||
        answer[0] == 'k' || answer[0] == 'K')
    {
      std::cout << WRONG_ANSWER;
      continue;
    }
    try
    {
      new_piece = createPieceFromArguments(*answer.c_str(), owner,
                                           position);
      right_anwser = true;
    }
    catch (Sep::SetupStringInvalidException &e)
    {
      std::cout << WRONG_ANSWER;
    }
  }
  return new_piece;
}
