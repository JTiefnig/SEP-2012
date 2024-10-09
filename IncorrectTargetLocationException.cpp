// --------------------------------------------------------------------------
// Filename: IncorrectstartingLocationException.cpp
//
//
//

// --------------------------------------------------------------------------

#include "IncorrectTargetLocationException.h"

using Sep::IncorrectTargetLocationException;

// --------------------------------------------------------------------------
IncorrectTargetLocationException::IncorrectTargetLocationException()
{
}

// --------------------------------------------------------------------------
IncorrectTargetLocationException::~IncorrectTargetLocationException() throw()
{
}

// --------------------------------------------------------------------------
const char *IncorrectTargetLocationException::what() const throw()
{
  return "Error: Incorrect target location.\n";
}
