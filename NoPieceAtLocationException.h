// ----------------------------------------------------------------------------
// Filename: NoPieceAtLocationException.h
// Description: Exception when no piece is on the start location
//
//
//

// ----------------------------------------------------------------------------

#ifndef NOPIECEATLOCATIONEXCEPTION_H_
#define NOPIECEATLOCATIONEXCEPTION_H_

#include "OwnBaseException.h"

namespace Sep
{
  class NoPieceAtLocationException : public OwnBaseException
  {
  public:
    // -----------------------------------------------------------------------
    // Construktor
    //
    NoPieceAtLocationException();

    // -----------------------------------------------------------------------
    // what, returns a error message or a description of the exception
    //
    // @return a error message or a description of the error
    //
    virtual const char *what() const throw();

    // -----------------------------------------------------------------------
    // destructor
    //
    virtual ~NoPieceAtLocationException() throw();
  };
}

#endif /* NOPIECEATLOCATIONEXCEPTION_H_ */
