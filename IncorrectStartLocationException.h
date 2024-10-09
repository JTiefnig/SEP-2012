// ----------------------------------------------------------------------------
// Filename: IncorrectStartLocationException.h
// Description: Exception in case of incorrect start location
//
//
//

// ----------------------------------------------------------------------------

#ifndef INCORRECTSTARTLOCATIONEXCEPTION_H_
#define INCORRECTSTARTLOCATIONEXCEPTION_H_

#include "OwnBaseException.h"

namespace Sep
{
  class IncorrectStartLocationException : public OwnBaseException
  {
  public:
    // -----------------------------------------------------------------------
    // Construktor
    //
    IncorrectStartLocationException();

    // -----------------------------------------------------------------------
    // what, returns a error message or a description of the exception
    //
    // @return a error message or a description of the error
    //
    virtual const char *what() const throw();

    // -----------------------------------------------------------------------
    // destructor
    //
    virtual ~IncorrectStartLocationException() throw();
  };
}

#endif /* INCORRECTSTARTLOCATIONEXCEPTION_H_ */
