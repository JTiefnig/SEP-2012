// --------------------------------------------------------------------------
// Filename: NoPieceAtLocationException.cpp
//
//
//

// --------------------------------------------------------------------------

#include "NoPieceAtLocationException.h"

using Sep::NoPieceAtLocationException;

// --------------------------------------------------------------------------
NoPieceAtLocationException::NoPieceAtLocationException()
{
}

// --------------------------------------------------------------------------
NoPieceAtLocationException::~NoPieceAtLocationException() throw()
{
}

// --------------------------------------------------------------------------
const char *NoPieceAtLocationException::what() const throw()
{
  return "Error: No piece at this location.\n";
}
