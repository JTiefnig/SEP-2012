// --------------------------------------------------------------------------
// Filename: main.cpp
// Description: Main program
// Created: 08.08.2011
// Last change: 08.08.2011
// --------------------------------------------------------------------------

#include "ChessGame.h"
#include "Game.h"
#include "OutOfMemoryException.h"
#include "OwnBaseException.h"
#include "Player.h"
#include "SetupStringCorruptException.h"
#include "SetupStringInvalidException.h"

#include <iostream>
#include <string.h>
#include <string>

using std::string;

static const string NORMAL_BOARD =
    "Ra1Nb1Bc1Qd1Ke1Bf1Ng1Rh1Pb2Pc2Pd2Pe2Pg2Ph2"
    "Pa2Pf2pb7pa7pc7pd7pe7pf7pg7ph7ra8nb8bc8qd8ke8bf8ng8rh8";

static const int INVALID_PARAMETER_COUNT = -1;
static const int OUT_OF_MEMORY = -2;
static const int INVALID_SETUP_STRING = -3;
static const int CORRUPT_SETUP_STRING = -4;
static const int SUCCESS = 0;
static const string INVALID_PARAMETER =
    "Error: Invalid parameter count.\n";

// --------------------------------------------------------------------------
int main(int argc, char **argv)
{
  bool bonus = false;
  bool input_error = false;
  string board_setup;

  switch (argc)
  {
  case 1:
    board_setup = NORMAL_BOARD;
    break;
  case 3:
  {
    string second_argument = argv[2];
    if (second_argument == "-b")
    {
      bonus = true;
    }
    else
    {
      input_error = true;
    }
    // No break here!!
  }
  case 2:
  {
    string first_argument = argv[1];
    if (first_argument == "-b")
    {
      board_setup = NORMAL_BOARD;
      bonus = true;
    }
    else
    {
      board_setup = first_argument;
    }
    break;
  }
  default:
    input_error = true;
  }
  if (input_error)
  {
    std::cout << INVALID_PARAMETER;
    return INVALID_PARAMETER_COUNT;
  }
  ChessGame *game = 0;
  try
  {
    game = new ChessGame(0, 0, bonus);
    game->addPlayer(new Player(WHITE, "White"));
    game->addPlayer(new Player(BLACK, "Black"));
    game->createBoardFromArguments(board_setup);
    game->run();
    delete game;
  }
  catch (std::bad_alloc &e)
  {
    delete game;
    game = 0;
    throw Sep::OutOfMemoryException();
  }
  catch (Sep::SetupStringCorruptException &e)
  {
    delete game;
    game = 0;
    std::cout << e.what();
    return CORRUPT_SETUP_STRING;
  }
  catch (Sep::SetupStringInvalidException &e)
  {
    delete game;
    game = 0;
    std::cout << e.what();
    return INVALID_SETUP_STRING;
  }
  catch (Sep::OutOfMemoryException &e)
  {
    delete game;
    game = 0;
    std::cout << e.what();
    return OUT_OF_MEMORY;
  }
  catch (Sep::OwnBaseException &e)
  {
    // catching whatever strange error might occur
    delete game;
    game = 0;
    std::cout << e.what();
  }
  return SUCCESS;
}
