// ----------------------------------------------------------------------------
// Filename: NoDrawOfferedException.h
// Description: Exception if the user input is draw decline, but if there was
// no draw offered
//
//
//

// ----------------------------------------------------------------------------

#ifndef NODRAWOFFEREDEXCEPTION_H_
#define NODRAWOFFEREDEXCEPTION_H_

#include "OwnBaseException.h"

namespace Sep
{
  class NoDrawOfferedException : public OwnBaseException
  {
  public:
    // -----------------------------------------------------------------------
    // Construktor
    //
    NoDrawOfferedException();

    // -----------------------------------------------------------------------
    // what, returns a error message or a description of the exception
    //
    // @return a error message or a description of the error
    //
    virtual const char *what() const throw();

    // -----------------------------------------------------------------------
    // destructor
    //
    virtual ~NoDrawOfferedException() throw();
  };
}

#endif /* NODRAWOFFEREDEXCEPTION_H_ */
