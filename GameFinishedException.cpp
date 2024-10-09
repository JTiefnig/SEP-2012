// --------------------------------------------------------------------------
// Filename: GameFinishedException.cpp
//
//
//

// --------------------------------------------------------------------------

#include "GameFinishedException.h"

using Sep::GameFinishedException;

// --------------------------------------------------------------------------
GameFinishedException::GameFinishedException()
{
}

// --------------------------------------------------------------------------
GameFinishedException::~GameFinishedException() throw()
{
}

// --------------------------------------------------------------------------
const char *GameFinishedException::what() const throw()
{
  return "Error: Game finished.\n";
}
