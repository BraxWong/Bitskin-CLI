#include "../header/CMDVector.h"
bool CMDStack::pushToStack(std::string command)
{
  if(command == "")
  {
    return false;
  }
  this->commandStack.push_back(command);
  return true;
}

std::string CMDStack::getLastCommand()
{
  if(currentIndex == 0)
  {
    return this->commandStack[commandStack.size() - 1];
    currentIndex = commandStack.size() - 2;
  }
  else 
  {
    return this->commandStack[currentIndex];
    if(currentIndex != 0)
    {
      currentIndex -= 1;
    }
  }
}
