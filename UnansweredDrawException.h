// ----------------------------------------------------------------------------
// Filename: UnansweredDrawException.h
// Description: Exception in case of a unanswered draw
//
//
//

// ----------------------------------------------------------------------------

#ifndef UNANSWEREDDRAWEXCEPTION_H_
#define UNANSWEREDDRAWEXCEPTION_H_

#include "OwnBaseException.h"

namespace Sep
{
  class UnansweredDrawException : public OwnBaseException
  {
  public:
    // -----------------------------------------------------------------------
    // Construktor
    //
    UnansweredDrawException();

    // -----------------------------------------------------------------------
    // what, returns a error message or a description of the exception
    //
    // @return a error message or a description of the error
    //
    virtual const char *what() const throw();

    // -----------------------------------------------------------------------
    // destructor
    //
    virtual ~UnansweredDrawException() throw();
  };
}

#endif /* UNANSWEREDDRAWEXCEPTION_H_ */
