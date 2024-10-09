// --------------------------------------------------------------------------
// Filename: CanNotSaveException.cpp
//
//
//

// --------------------------------------------------------------------------

#include "CanNotSaveException.h"

using Sep::CanNotSaveException;
using std::string;

// --------------------------------------------------------------------------
CanNotSaveException::CanNotSaveException(const string file_name)
{
  exception_text_ = "Error: Cannot save to file " + file_name + ".\n";
}

// --------------------------------------------------------------------------
CanNotSaveException::~CanNotSaveException() throw()
{
}

// --------------------------------------------------------------------------
const char *CanNotSaveException::what() const throw()
{
  return exception_text_.c_str();
}
