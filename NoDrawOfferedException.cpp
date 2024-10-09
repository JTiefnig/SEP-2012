// --------------------------------------------------------------------------
// Filename: NoDrawOfferedException.cpp
//
//
//

// --------------------------------------------------------------------------

#include "NoDrawOfferedException.h"

using Sep::NoDrawOfferedException;

// --------------------------------------------------------------------------
NoDrawOfferedException::NoDrawOfferedException()
{
}

// --------------------------------------------------------------------------
NoDrawOfferedException::~NoDrawOfferedException() throw()
{
}

// --------------------------------------------------------------------------
const char *NoDrawOfferedException::what() const throw()
{
  return "Error: No draw offered.\n";
}
