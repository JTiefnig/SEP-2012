// --------------------------------------------------------------------------
// Filename: InternalErrorException.cpp
//
//
//

// --------------------------------------------------------------------------

#include "InternalErrorException.h"

using Sep::InternalErrorException;

// --------------------------------------------------------------------------
InternalErrorException::InternalErrorException()
{
}

// --------------------------------------------------------------------------
InternalErrorException::~InternalErrorException() throw()
{
}

// --------------------------------------------------------------------------
const char *InternalErrorException::what() const throw()
{
  return "Error: An internal Error occured.\n";
}
