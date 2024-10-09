// --------------------------------------------------------------------------
// Filename: SetupStringInvalidException.h
// Description: Exception in case of a invalid input string
//
//
//

// --------------------------------------------------------------------------

#ifndef SETUPSTRINGINVALIDEXCEPTION_H_
#define SETUPSTRINGINVALIDEXCEPTION_H_

#include "OwnBaseException.h"

namespace Sep
{
  class SetupStringInvalidException : public OwnBaseException
  {
  public:
    // ----------------------------------------------------------------------
    // Construktor
    //
    SetupStringInvalidException();

    // ----------------------------------------------------------------------
    // what, returns a error message or a description of the exception
    //
    // @return a error message or a description of the error
    //
    virtual const char *what() const throw();

    // ----------------------------------------------------------------------
    // destructor
    //
    virtual ~SetupStringInvalidException() throw();
  };
}

#endif /* SETUPSTRINGINVALID_H_ */
