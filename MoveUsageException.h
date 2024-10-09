// ----------------------------------------------------------------------------
// Filename: MoveUsageException.h
// Description: Exception in case of wrong usage of move command
//
//
//

// ----------------------------------------------------------------------------

#ifndef MOVEUSAGEEXCEPTION_H_
#define MOVEUSAGEEXCEPTION_H_

#include "OwnBaseException.h"

namespace Sep
{
  class MoveUsageException : public OwnBaseException
  {
  public:
    // -----------------------------------------------------------------------
    // Construktor
    //
    MoveUsageException();

    // -----------------------------------------------------------------------
    // what, returns a error message or a description of the exception
    //
    // @return a error message or a description of the error
    //
    virtual const char *what() const throw();

    // -----------------------------------------------------------------------
    // destructor
    //
    virtual ~MoveUsageException() throw();
  };
}
#endif /* MOVEUSAGEEXCEPTION_H_ */
