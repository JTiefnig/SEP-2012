// -----------------------------------------------------------------------------
// Filename: OwnPieceOnTargetException.h
// Description: Exception when one of your own pieces stands on the target
// location
//
//
//

// -----------------------------------------------------------------------------

#ifndef OWNPIECEONTARGETEXCEPTION_H_
#define OWNPIECEONTARGETEXCEPTION_H_

#include "OwnBaseException.h"

namespace Sep
{
  class OwnPieceOnTargetException : public OwnBaseException
  {
  public:
    // -----------------------------------------------------------------------
    // Construktor
    //
    OwnPieceOnTargetException();

    // -----------------------------------------------------------------------
    // what, returns a error message or a description of the exception
    //
    // @return a error message or a description of the error
    //
    virtual const char *what() const throw();

    // -----------------------------------------------------------------------
    // destructor
    //
    virtual ~OwnPieceOnTargetException() throw();
  };
}

#endif /* OWNPIECEONTARGETEXCEPTION_H_ */
