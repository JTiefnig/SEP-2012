// --------------------------------------------------------------------------
// Filename: IncorrectTargetLocationException.h
// Description: Exception in case of incorrect target location
//
//
//

// --------------------------------------------------------------------------

#ifndef INCORRECTTARGETLOCATION_H_
#define INCORRECTTARGETLOCATION_H_

#include "OwnBaseException.h"

namespace Sep
{
  class IncorrectTargetLocationException : public OwnBaseException
  {
  public:
    // -----------------------------------------------------------------------
    // Construktor
    //
    IncorrectTargetLocationException();

    // -----------------------------------------------------------------------
    // what, returns a error message or a description of the exception
    //
    // @return a error message or a description of the error
    //
    virtual const char *what() const throw();

    // -----------------------------------------------------------------------
    // destructor
    //
    virtual ~IncorrectTargetLocationException() throw();
  };
}

#endif /* INCORRECTSTARTINGLOCATION_H_ */
