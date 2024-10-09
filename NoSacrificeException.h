// ----------------------------------------------------------------------------
// Filename: NoSacrificeException.h
// Description: Exception when the king can be attecked, caused by the own
// move
//
//
//

// ----------------------------------------------------------------------------

#ifndef NOSACRIFICEEXCEPTION_H_
#define NOSACRIFICEEXCEPTION_H_

#include "OwnBaseException.h"

namespace Sep
{
  class NoSacrificeException : public OwnBaseException
  {
  public:
    // -----------------------------------------------------------------------
    // Construktor
    //
    NoSacrificeException();

    // -----------------------------------------------------------------------
    // what, returns a error message or a description of the exception
    //
    // @return a error message or a description of the error
    //
    virtual const char *what() const throw();

    // -----------------------------------------------------------------------
    // destructor
    //
    virtual ~NoSacrificeException() throw();
  };
}

#endif /* NOSACRIFICEEXCEPTION_H_ */
