// --------------------------------------------------------------------------
// Filename: NoSacrificeException.cpp
//
//
//

// --------------------------------------------------------------------------

#include "NoSacrificeException.h"

using Sep::NoSacrificeException;

// --------------------------------------------------------------------------
NoSacrificeException::NoSacrificeException()
{
}

// --------------------------------------------------------------------------
NoSacrificeException::~NoSacrificeException() throw()
{
}

// --------------------------------------------------------------------------
const char *NoSacrificeException::what() const throw()
{
  return "Error: No sacrifice allowed.\n";
}
