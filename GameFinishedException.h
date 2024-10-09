// --------------------------------------------------------------------------
// Filename: GameFinishedException.h
// Description: Exception when the game finished and a wrong command was
// typed
//
//
//

// --------------------------------------------------------------------------

#ifndef GAMEFINISHEDEXCEPTION_H_
#define GAMEFINISHEDEXCEPTION_H_

#include "OwnBaseException.h"

namespace Sep
{
  class GameFinishedException : public OwnBaseException
  {
  public:
    // --------------------------------------------------------------------
    // Construktor
    //
    GameFinishedException();

    // --------------------------------------------------------------------
    // what, returns a error message or a description of the exception
    //
    // @return a error message or a description of the error
    //
    virtual const char *what() const throw();

    // --------------------------------------------------------------------
    // destructor
    //
    virtual ~GameFinishedException() throw();
  };
}

#endif /* GAMEFINISHEDEXCEPTION_H_ */
