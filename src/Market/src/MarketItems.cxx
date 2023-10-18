#include "../header/MarketItems.h"
#include <iostream>
#include <string>
#include <vector>

void MarketItems::userStores(std::string input)
{
  if(input.find("-h") != std::string::npos)
  {
    this->help->showHelp(false, input);
  }

  std::string storeAlias, storeHash;
  std::cout << "Please provide your store alias.\n";
  std::getline(std::cin, storeAlias);
  std::cout << "Please provide the storeHash (Press enter if you don't have one):\n";
  std::getline(std::cin, storeHash);
  if(storeHash != "")
  {
    std::vector<std::string> keys = {"store_alias", "store_hash"};
    std::vector<std::string> values = {storeAlias, storeHash};
    std::vector<std::string> dataTypes = {"String", "String"};
    this->executeBash->executeBashScript("https://api.bitskins.com/market/search/store", this->profile->user->getAPIKey(), keys, values, dataTypes);
  }
  else 
  {
    std::vector<std::string> keys = {"store_alias"};
    std::vector<std::string> values = {storeAlias};
    std::vector<std::string> dataTypes = {"String"};
    this->executeBash->executeBashScript("https://api.bitskins.com/market/search/store", this->profile->user->getAPIKey(), keys, values, dataTypes);
  }
}


