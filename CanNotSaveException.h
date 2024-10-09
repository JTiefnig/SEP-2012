// --------------------------------------------------------------------------
// Filename: CanNotSaveException.h
// Description: Exception in case of saving the outputfile failed
//
//
//

// --------------------------------------------------------------------------

#ifndef CANNOTSAVEEXCEPTION_H_
#define CANNOTSAVEEXCEPTION_H_

#include "OwnBaseException.h"

#include <string>

namespace Sep
{
  class CanNotSaveException : public OwnBaseException
  {
  private:
    // --------------------------------------------------------------------
    // text which will be returned by the what method
    //
    std::string exception_text_;

  public:
    // --------------------------------------------------------------------
    // Construktor
    //
    CanNotSaveException(std::string file_name);

    // --------------------------------------------------------------------
    // what, returns a error message or a description of the exception
    //
    // @return a error message or a description of the error
    //
    virtual const char *what() const throw();

    // --------------------------------------------------------------------
    // destructor
    //
    virtual ~CanNotSaveException() throw();
  };
}

#endif /* CANNOTSAVEEXCEPTION_H_ */
