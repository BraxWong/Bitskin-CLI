#include "../header/WalletDeposit.h"
#include <iostream>
#include <string>

bool WalletDespoit::depositBinance(std::string input)
{
  if(input.find("-h") != std::string::npos)
  {
    this->help->showHelp(false, input);
  }

  std::string amount;
  std::cout << "Please select the amount you want to deposit\n";
  std::getline(std::cin, amount);
  std::vector<std::string> keys = {"amount"};
  std::vector<std::string> values = {amount};
  std::vector<std::string> dataTypes = {"Number"};

  this->executeBash->executeBashScript("https://api.bitskins.com/wallet/deposit/binancepay/create", this->profile->user->getAPIKey(), keys, values, dataTypes);

  return true;
}

