#include "../header/WalletReports.h"
#include <iostream>
#include <string>

bool WalletReports::getWalletReports(std::string input)
{
  if(input.find("-h") != std::string::npos)
  {
    this->help->showHelp(false, input);
  }
  std::string type, status;
  std::cout << "Please enter the type: \n";
  std::getline(std::cin, type);
  std::cout << "Please enter the status: \n";
  std::getline(std::cin, status);
  std::vector<std::string> keys = {"type","status"};
  std::vector<std::string> values = {type, status};
  std::vector<std::string> dataTypes = {"Number", "Number"};

  this->executeBash->executeBashScript("https://api.bitskins.com/wallet/report/list", this->profile->user->getAPIKey(), keys, values, dataTypes);

  return true;

}

