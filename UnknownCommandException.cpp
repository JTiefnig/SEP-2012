// --------------------------------------------------------------------------
// Filename: UnknownCommandException.cpp
//
//
//

// --------------------------------------------------------------------------

#include "UnknownCommandException.h"

using Sep::UnknownCommandException;

// --------------------------------------------------------------------------
UnknownCommandException::UnknownCommandException()
{
}

// --------------------------------------------------------------------------
UnknownCommandException::~UnknownCommandException() throw()
{
}

// --------------------------------------------------------------------------
const char *UnknownCommandException::what() const throw()
{
  return "Error: Unknown command.\n";
}
