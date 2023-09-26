#include "../header/Help.h"
#include <iostream>
#include <stdio.h>

void Help::showHelp(bool fromHelpPage, std::string command)
{
  if(fromHelpPage)
  {
    std::cout << "Help Page:\n";
    std::cout << "Currently this program has 6 commands available.\n";
    std::cout << "1: -help\n2: -quit\n3: -balance\n4: -session\n5: -tradelink\n6: -updateaccount\n7: -block\n";
    std::cout << "To obtain for information regarding one specific command, type in the command you want with the argument -h\n";
    std::cout << "For example: -quit -h\n";
    std::cout << "Enter -q to leave the help page.\n";
  }
  while(true)
  {
    if(fromHelpPage)
    {
      std::getline(std::cin,command);
    }
    if(command == "-quit -h")
    {
      std::cout << "When -quit is entered, the program will be terminated.\n";
    }
    else if(command == "-help -h")
    {
      std::cout << "When -help is entered, a list of commands will be displayed. Users can add the extra argument -h along with their command to obtain the information regarding that command.\n";
    }
    else if(command == "-balance -h")
    {
      std::cout << "When -balance is entered, the user's balance on the website Bitskins will be displayed.\n";
    }
    else if(command == "-session -h")
    {
      std::cout << "When -session is entered, a list of information regarding the user's current Bitskins session will be displayed. Information such as steam-id, email, country, steam username and more will be shown.\n";
    }
    else if(command == "-tradelink -h")
    {
      std::cout << "When -tradelink is entered, the user will be required to enter their updated steam trade link in order to update this information on Bitskins.\n";
    }
    else if(command == "-updateaccount -h")
    {
      std::cout << "When -updateaccount is entered, the user will be presented the option to update a selection of information on Bitskins. Such as: Currency, language, store_alias and more.\n";
    }
    else if(command == "-block -h")
    {
      std::cout << "When -block is entered, the user's Bitskins account will be blocked. WARNING!!!You will have to go to Bitskins website in order to unblock your account. Use this command only if you really have to.\n";
    }
    else if(command == "-q")
    {
      break;
    }
    if(!fromHelpPage)
    {
      break;
    }
  }
}
