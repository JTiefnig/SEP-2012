// --------------------------------------------------------------------------
// Filename: SetupStringCorruptException.cpp
//
//
//

// --------------------------------------------------------------------------

#include "SetupStringCorruptException.h"

using Sep::SetupStringCorruptException;

// --------------------------------------------------------------------------
SetupStringCorruptException::SetupStringCorruptException()
{
}

// --------------------------------------------------------------------------
SetupStringCorruptException::~SetupStringCorruptException() throw()
{
}

// --------------------------------------------------------------------------
const char *SetupStringCorruptException::what() const throw()
{
  return "Error: setup string corrupt.\n";
}
