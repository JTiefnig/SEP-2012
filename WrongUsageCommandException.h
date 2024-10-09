// --------------------------------------------------------------------------
// Filename: WrongUsageCommandException.h
// Description: Exception in case of wrong usage of the command
//
//
//

// --------------------------------------------------------------------------

#ifndef WRONGUSAGECOMMANDEXCEPTION_H_
#define WRONGUSAGECOMMANDEXCEPTION_H_

#include "OwnBaseException.h"

namespace Sep
{
  class WrongUsageCommandException : public OwnBaseException
  {
  public:
    // --------------------------------------------------------------------
    // Construktor
    //
    WrongUsageCommandException();

    // --------------------------------------------------------------------
    // what, returns a error message or a description of the exception
    //
    // @return a error message or a description of the error
    //
    virtual const char *what() const throw();

    // --------------------------------------------------------------------
    // destructor
    //
    virtual ~WrongUsageCommandException() throw();
  };
}

#endif /* WRONGUSAGECOMMANDEXCEPTION_H_ */
