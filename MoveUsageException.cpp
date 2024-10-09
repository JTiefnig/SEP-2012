// --------------------------------------------------------------------------
// Filename: MoveUsageException.cpp
//
//
//

// --------------------------------------------------------------------------

#include "MoveUsageException.h"

using Sep::MoveUsageException;

// --------------------------------------------------------------------------
MoveUsageException::MoveUsageException()
{
}

// --------------------------------------------------------------------------
MoveUsageException::~MoveUsageException() throw()
{
}

// --------------------------------------------------------------------------
const char *MoveUsageException::what() const throw()
{
  return "Usage: move startlocation endlocation.\n";
}
