// --------------------------------------------------------------------------
// Filename: SetupStringCorruptException.h
// Description: Exception in case of a corrupt string input
//
//
//

// --------------------------------------------------------------------------

#ifndef SETUPSTRINGCORRUPTEXCEPTION_H_
#define SETUPSTRINGCORRUPTEXCEPTION_H_

#include "OwnBaseException.h"

namespace Sep
{
  class SetupStringCorruptException : public OwnBaseException
  {
  public:
    // ----------------------------------------------------------------------
    // Construktor
    //
    SetupStringCorruptException();

    // ----------------------------------------------------------------------
    // what, returns a error message or a description of the exception
    //
    // @return a error message or a description of the error
    //
    virtual const char *what() const throw();

    // ----------------------------------------------------------------------
    // destructor
    //
    virtual ~SetupStringCorruptException() throw();
  };
}
#endif /* SETUPSTRINGCORRUPTEXCEPTION_H_ */
