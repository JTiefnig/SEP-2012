// --------------------------------------------------------------------------
// Filename: TargetNotReachableException.cpp
//
//
//

// --------------------------------------------------------------------------

#include "TargetNotReachableException.h"

using Sep::TargetNotReachableException;

// --------------------------------------------------------------------------
TargetNotReachableException::TargetNotReachableException()
{
}

// --------------------------------------------------------------------------
TargetNotReachableException::~TargetNotReachableException() throw()
{
}

// --------------------------------------------------------------------------
const char *TargetNotReachableException::what() const throw()
{
  return "Error: target location not reachable.\n";
}
