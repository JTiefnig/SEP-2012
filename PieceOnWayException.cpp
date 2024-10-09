// --------------------------------------------------------------------------
// Filename: PieceOnWayException.cpp
//
//
//

// --------------------------------------------------------------------------

#include "PieceOnWayException.h"

using Sep::PieceOnWayException;

// --------------------------------------------------------------------------
PieceOnWayException::PieceOnWayException()
{
}

// --------------------------------------------------------------------------
PieceOnWayException::~PieceOnWayException() throw()
{
}

// --------------------------------------------------------------------------
const char *PieceOnWayException::what() const throw()
{
  return "Error: Piece on the way.\n";
}
