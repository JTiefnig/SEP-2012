// --------------------------------------------------------------------------
// Filename: SaveUsageException.h
// Description: Exception in case of a the wrong usage of the command save
//
//
//

// --------------------------------------------------------------------------

#ifndef SAVEUSAGEEXCEPTION_H_
#define SAVEUSAGEEXCEPTION_H_

#include "OwnBaseException.h"

namespace Sep
{
  class SaveUsageException : public OwnBaseException
  {
  public:
    // ----------------------------------------------------------------------
    // Construktor
    //
    SaveUsageException();

    // ----------------------------------------------------------------------
    // what, returns a error message or a description of the exception
    //
    // @return a error message or a description of the error
    //
    virtual const char *what() const throw();

    // ----------------------------------------------------------------------
    // destructor
    //
    virtual ~SaveUsageException() throw();
  };
}

#endif /* SAVEUSAGEEXCEPTION_H_ */
