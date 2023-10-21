#include <iostream>
#include <stack>
#include <string>

class CMDStack
{
  public:
    std::stack<std::string>commandStack;
    std::string getLastCommand(); 
    bool pushToStack(std::string command);
};
