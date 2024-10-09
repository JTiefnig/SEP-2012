// --------------------------------------------------------------------------
// Filename: SaveUsageException.cpp
//
//
//

// --------------------------------------------------------------------------

#include "SaveUsageException.h"

using Sep::SaveUsageException;

// --------------------------------------------------------------------------
SaveUsageException::SaveUsageException()
{
}

// --------------------------------------------------------------------------
SaveUsageException::~SaveUsageException() throw()
{
}

// --------------------------------------------------------------------------
const char *SaveUsageException::what() const throw()
{
  return "Usage: save filename.\n";
}
