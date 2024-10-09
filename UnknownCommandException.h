// ----------------------------------------------------------------------------
// Filename: UnknownCommandException.h
// Description: Exception in case of Unknown command input
//
//
//

// ----------------------------------------------------------------------------

#ifndef UNKNOWNCOMMANDEXCEPTION_H_
#define UNKNOWNCOMMANDEXCEPTION_H_

#include "OwnBaseException.h"

namespace Sep
{
  class UnknownCommandException : public OwnBaseException
  {
  public:
    // -----------------------------------------------------------------------
    // Construktor
    //
    UnknownCommandException();

    // -----------------------------------------------------------------------
    // what, returns a error message or a description of the exception
    //
    // @return a error message or a description of the error
    //
    virtual const char *what() const throw();

    // -----------------------------------------------------------------------
    // destructor
    //
    virtual ~UnknownCommandException() throw();
  };
}
#endif /* UNKNOWNCOMMANDEXCEPTION_H_ */
