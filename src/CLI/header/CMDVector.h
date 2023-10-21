#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>

class CMDStack
{
  public:
    std::vector<std::string>commandStack;
    std::string getLastCommand(); 
    bool pushToStack(std::string command);
    int currentIndex = 0; 
};
