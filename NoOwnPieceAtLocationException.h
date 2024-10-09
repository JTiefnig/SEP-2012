// ----------------------------------------------------------------------------
// Filename: NoOwnPieceAtLocationException.h
// Description: Exception when no own piece is on the starting location
//
//
//

// ----------------------------------------------------------------------------

#ifndef NOOWNPIECEATLOCATIONEXCEPTION_H_
#define NOOWNPIECEATLOCATIONEXCEPTION_H_

#include "OwnBaseException.h"

namespace Sep
{
  class NoOwnPieceAtLocationException : public OwnBaseException
  {
  public:
    // -----------------------------------------------------------------------
    // Construktor
    //
    NoOwnPieceAtLocationException();

    // -----------------------------------------------------------------------
    // what, returns a error message or a description of the exception
    //
    // @return a error message or a description of the error
    //
    virtual const char *what() const throw();

    // -----------------------------------------------------------------------
    // destructor
    //
    virtual ~NoOwnPieceAtLocationException() throw();
  };
}

#endif /* NOOWNPIECEATLOCATIONEXCEPTION_H_ */
