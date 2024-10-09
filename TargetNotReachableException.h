// -----------------------------------------------------------------------------
// Filename: TargetNotReachableException.h
// Description: Exception if the target location is not reachable, cause of
// the move pattern
//
//
//

// -----------------------------------------------------------------------------

#ifndef TARGETNOTREACHABLEEXCEPTION_H_
#define TARGETNOTREACHABLEEXCEPTION_H_

#include "OwnBaseException.h"

namespace Sep
{
  class TargetNotReachableException : public OwnBaseException
  {
  public:
    // -----------------------------------------------------------------------
    // Construktor
    //
    TargetNotReachableException();

    // -----------------------------------------------------------------------
    // what, returns a error message or a description of the exception
    //
    // @return a error message or a description of the error
    //
    virtual const char *what() const throw();

    // -----------------------------------------------------------------------
    // destructor
    //
    virtual ~TargetNotReachableException() throw();
  };
}

#endif /* TARGETNOTREACHABLEEXCEPTION_H_ */
