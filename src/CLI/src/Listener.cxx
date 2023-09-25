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
    std::getline(std::cin, input);
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
    else if(input == "-tradelink")
    {
      this->profile->updateTradeLink();
    }
    else if(input == "-updateaccount")
    {
      this->profile->updateAccount();
    }
    else if(input == "-block")
    {
      this->profile->blockAccount();
    }
    else 
    {
      std::cout << "Command not recognized. Please try again.\n";
    }
  }
}
