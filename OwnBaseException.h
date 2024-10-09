// -----------------------------------------------------------------------------
// OwnBaseException.h
//
//
//

// -----------------------------------------------------------------------------
//

#ifndef OWNBASEEXCEPTION_H_INCLUDED
#define OWNBASEEXCEPTION_H_INCLUDED

#include <exception>

namespace Sep
{
  // ---------------------------------------------------------------------------
  // Base for all exceptions
  //
  class OwnBaseException : public std::exception
  {
  public:
    // -----------------------------------------------------------------------
    // Construktor
    //
    OwnBaseException();

    // -----------------------------------------------------------------------
    // what, returns a error message or a description of the exception
    //
    // @return a error message or a description of the error
    //
    virtual const char *what() const throw() = 0;

    // -----------------------------------------------------------------------
    // destructor
    //
    virtual ~OwnBaseException() throw();
  };
}

#endif // OWNBASEEXCEPTION_H_INCLUDED
