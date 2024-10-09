// --------------------------------------------------------------------------
// Filename: IncorrectStartLocationException.cpp
//
//
//

// --------------------------------------------------------------------------

#include "IncorrectStartLocationException.h"

using Sep::IncorrectStartLocationException;

// --------------------------------------------------------------------------
IncorrectStartLocationException::IncorrectStartLocationException()
{
}

// --------------------------------------------------------------------------
IncorrectStartLocationException::~IncorrectStartLocationException() throw()
{
}

// --------------------------------------------------------------------------
const char *IncorrectStartLocationException::what() const throw()
{
  return "Error: Incorrect starting location.\n";
}
