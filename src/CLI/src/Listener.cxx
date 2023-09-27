#include "../header/Listener.h"
#include "../header/Help.h"
#include <iostream>
#include <stdio.h>
#include <unistd.h>

void Listener::listenCommand()
{
  Help* help = new Help();
  std::string input;
  while (true)
  {
    std::cout << "Please enter a command to get started. If you need help with the program, please enter -help.\n";
    std::getline(std::cin, input);
    if(input == "-help")
    {
      help->showHelp(true); 
    }
    else if(input == "-quit")   
    {
      break;
    }
    else if(input.find("-balance"))
    {
      this->profile->getAccountBalance(input);
    }
    else if(input.find("-session"))
    {
      this->profile->getCurrentSession(input);
    }
    else if(input.find("-tradelink"))
    {
      this->profile->updateTradeLink(input);
    }
    else if(input.find("-updateaccount"))
    {
      this->profile->updateAccount(input);
    }
    else if(input.find("-block"))
    {
      this->profile->blockAccount(input);
    }
    else 
    {
      std::cout << "Command not recognized. Please try again.\n";
    }
  }
}
