#include "../header/CMDStack.h"

bool CMDStack::pushToStack(std::string command)
{
  if(command == "")
  {
    return false;
  }
  this->commandStack.push(command);
  return true;
}
