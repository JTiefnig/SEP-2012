// --------------------------------------------------------------------------
// Filename: SetupStringInvalidException.cpp
//
//
//

// --------------------------------------------------------------------------

#include "SetupStringInvalidException.h"

using Sep::SetupStringInvalidException;

// --------------------------------------------------------------------------
SetupStringInvalidException::SetupStringInvalidException()
{
}

// --------------------------------------------------------------------------
SetupStringInvalidException::~SetupStringInvalidException() throw()
{
}

// --------------------------------------------------------------------------
const char *SetupStringInvalidException::what() const throw()
{
  return "Error: setup string invalid.\n";
}
