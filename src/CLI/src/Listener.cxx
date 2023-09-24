#include "../header/Listener.h"
#include "../header/Help.h"
#include <iostream>
#include <stdio.h>
#include <unistd.h>

void Listener::listenCommand()
{
  bool terminateProgram = false;
  Help* help = new Help();
  std::string input;
  while (true)
  {
    std::cout << "Please enter a command to get started. If you need help with the program, please enter -help.\n";
    std::cin >> input;
    if(input == "-help")
    {
      help->showHelp(); 
    }
    else if(input == "-quit")   
    {
      delete help;     
      break;
    }
    else if(input == "-balance")
    {
      this->profile->getAccountBalance();
    }
    else if(input == "-session")
    {
      this->profile->getCurrentSession();
    }
  }
}
