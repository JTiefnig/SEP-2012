// ----------------------------------------------------------------------------
// Filename: InternalErrorException.h
// Description: Exception if a internal (not defined) error happens
//
//
//

// ----------------------------------------------------------------------------

#ifndef INTERNALERROREXCEPTION_H_
#define INTERNALERROREXCEPTION_H_

#include "OwnBaseException.h"

namespace Sep
{
  class InternalErrorException : public OwnBaseException
  {
  public:
    // -----------------------------------------------------------------------
    // Construktor
    //
    InternalErrorException();

    // -----------------------------------------------------------------------
    // what, returns a error message or a description of the exception
    //
    // @return a error message or a description of the error
    //
    virtual const char *what() const throw();

    // -----------------------------------------------------------------------
    // destructor
    //
    virtual ~InternalErrorException() throw();
  };
}

#endif /* INTERNALERROREXCEPTION_H_ */
