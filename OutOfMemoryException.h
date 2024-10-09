// --------------------------------------------------------------------------
// Filename: OutOfMemoryException.h
// Description: Exception in case of bad alloc
//
//
//

// --------------------------------------------------------------------------

#ifndef OUTOFMEMORYEXCEPTION_H_
#define OUTOFMEMORYEXCEPTION_H_

#include "OwnBaseException.h"

namespace Sep
{
  class OutOfMemoryException : public OwnBaseException
  {
  public:
    // -----------------------------------------------------------------------
    // Construktor
    //
    OutOfMemoryException();

    // -----------------------------------------------------------------------
    // what, returns a error message or a description of the exception
    //
    // @return a error message or a description of the error
    //
    virtual const char *what() const throw();

    // -----------------------------------------------------------------------
    // destructor
    //
    virtual ~OutOfMemoryException() throw();
  };
}

#endif /* OUTOFMEMORYEXCEPTION_H_ */
