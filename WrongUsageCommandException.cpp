// --------------------------------------------------------------------------
// Filename: WrongUsageCommandException.cpp
//
//
//

// --------------------------------------------------------------------------

#include "WrongUsageCommandException.h"

using Sep::WrongUsageCommandException;

// --------------------------------------------------------------------------
WrongUsageCommandException::WrongUsageCommandException()
{
}

// --------------------------------------------------------------------------
WrongUsageCommandException::~WrongUsageCommandException() throw()
{
}

// --------------------------------------------------------------------------
const char *WrongUsageCommandException::what() const throw()
{
  return "Error: Wrong usage of command.\n";
}
