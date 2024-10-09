// --------------------------------------------------------------------------
// Filename: UnansweredDrawException.cpp
//
//
//

// --------------------------------------------------------------------------

#include "UnansweredDrawException.h"

using Sep::UnansweredDrawException;

// --------------------------------------------------------------------------
UnansweredDrawException::UnansweredDrawException()
{
}

// --------------------------------------------------------------------------
UnansweredDrawException::~UnansweredDrawException() throw()
{
}

// --------------------------------------------------------------------------
const char *UnansweredDrawException::what() const throw()
{
  return "Error: Unanswered draw offer.\n";
}
