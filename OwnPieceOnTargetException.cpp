// --------------------------------------------------------------------------
// Filename: OwnPieceOnTargetException.cpp
//
//
//

// --------------------------------------------------------------------------

#include "OwnPieceOnTargetException.h"

using Sep::OwnPieceOnTargetException;

// --------------------------------------------------------------------------
OwnPieceOnTargetException::OwnPieceOnTargetException()
{
}

// --------------------------------------------------------------------------
OwnPieceOnTargetException::~OwnPieceOnTargetException() throw()
{
}

// --------------------------------------------------------------------------
const char *OwnPieceOnTargetException::what() const throw()
{
  return "Error: Own piece on target location.\n";
}
