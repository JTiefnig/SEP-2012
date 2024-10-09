// --------------------------------------------------------------------------
// Filename: UsageDrawException.cpp
//
//
//

// --------------------------------------------------------------------------

#include "UsageDrawException.h"

using Sep::UsageDrawException;

// --------------------------------------------------------------------------
UsageDrawException::UsageDrawException()
{
}

// --------------------------------------------------------------------------
UsageDrawException::~UsageDrawException() throw()
{
}

// --------------------------------------------------------------------------
const char *UsageDrawException::what() const throw()
{
  return "Usage: draw [decline].\n";
}
