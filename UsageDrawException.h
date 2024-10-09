// ----------------------------------------------------------------------------
// Filename: UsageDrawException.h
// Description: Exception in case of the command draw is used wrong
//
//
//

// ----------------------------------------------------------------------------

#ifndef USAGEDRAWEXCEPTION_H_
#define USAGEDRAWEXCEPTION_H_

#include "OwnBaseException.h"

namespace Sep
{
  class UsageDrawException : public OwnBaseException
  {
  public:
    // -----------------------------------------------------------------------
    // Construktor
    //
    UsageDrawException();

    // -----------------------------------------------------------------------
    // what, returns a error message or a description of the exception
    //
    // @return a error message or a description of the error
    //
    virtual const char *what() const throw();

    // -----------------------------------------------------------------------
    // destructor
    //
    virtual ~UsageDrawException() throw();
  };
}

#endif /* USAGEDRAWEXCEPTION_H_ */
