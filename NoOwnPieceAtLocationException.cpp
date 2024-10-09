// --------------------------------------------------------------------------
// Filename: NoOwnPieceAtLocationException.cpp
//
//
//

// --------------------------------------------------------------------------

#include "NoOwnPieceAtLocationException.h"

using Sep::NoOwnPieceAtLocationException;

// --------------------------------------------------------------------------
NoOwnPieceAtLocationException::NoOwnPieceAtLocationException()
{
}

// --------------------------------------------------------------------------
NoOwnPieceAtLocationException::~NoOwnPieceAtLocationException() throw()
{
}

// --------------------------------------------------------------------------
const char *NoOwnPieceAtLocationException::what() const throw()
{
  return "Error: No own piece at this location.\n";
}
