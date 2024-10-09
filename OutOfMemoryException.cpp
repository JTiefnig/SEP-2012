// --------------------------------------------------------------------------
// Filename: OutOfMemoryException.cpp
//
//
//

// --------------------------------------------------------------------------

#include "OutOfMemoryException.h"

using Sep::OutOfMemoryException;

// --------------------------------------------------------------------------
OutOfMemoryException::OutOfMemoryException()
{
}

// --------------------------------------------------------------------------
OutOfMemoryException::~OutOfMemoryException() throw()
{
}

// --------------------------------------------------------------------------
const char *OutOfMemoryException::what() const throw()
{
  return "Error: Out of memory.\n";
}
