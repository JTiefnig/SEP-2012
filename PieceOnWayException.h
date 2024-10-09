// --------------------------------------------------------------------------
// Filename: PieceOnWayException.h
// Description: Exception if a piece on the way of the move
//
//
//

// --------------------------------------------------------------------------

#ifndef PIECEONWAYEXCEPTION_H_
#define PIECEONWAYEXCEPTION_H_

#include "OwnBaseException.h"

namespace Sep
{
  class PieceOnWayException : public OwnBaseException
  {
  public:
    // --------------------------------------------------------------------
    // Construktor
    //
    PieceOnWayException();

    // --------------------------------------------------------------------
    // what, returns a error message or a description of the exception
    //
    // @return a error message or a description of the error
    //
    virtual const char *what() const throw();

    // --------------------------------------------------------------------
    // destructor
    //
    virtual ~PieceOnWayException() throw();
  };
}

#endif /* PIECEONWAYEXCEPTION_H_ */
