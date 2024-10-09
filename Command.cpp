// --------------------------------------------------------------------------
// Filename: Command.cpp
//
//
//

// --------------------------------------------------------------------------

#include "Command.h"
#include <iostream>

// --------------------------------------------------------------------------

using std::cout;
using std::endl;
using std::string;

// --------------------------------------------------------------------------
Command::Command(string name, Game *board) : command_name_(name), board_(board)
{
}

// --------------------------------------------------------------------------
Command::Command(string name) : command_name_(name), board_(0)
{
}

Command::~Command()
{
}

// --------------------------------------------------------------------------
const std::string &Command::getName()
{
  return command_name_;
}
