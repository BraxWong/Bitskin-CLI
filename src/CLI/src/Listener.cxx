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
      delete help;     
      break;
    }
    else if(input.find("-balance") != std::string::npos)
    {
      this->profile->getAccountBalance(input);
    }
    else if(input.find("-session") != std::string::npos)
    {
      this->profile->getCurrentSession(input);
    }
    else if(input.find("-tradelink") != std::string::npos)
    {
      this->profile->updateTradeLink(input);
    }
    else if(input.find("-updateaccount") != std::string::npos)
    {
      this->profile->updateAccount(input);
    }
    else if(input.find("-block") != std::string::npos)
    {
      this->profile->blockAccount(input);
    }
    else if(input.find("-affiliate") != std::string::npos)
    {
      this->affiliate->getAffiliateInfo(input);
    }
    else if(input.find("-claimmoney") != std::string::npos)
    {
      this->affiliate->claimMoney(input);
    }
    else 
    {
      std::cout << "Command not recognized. Please try again.\n";
    }
  }
}
