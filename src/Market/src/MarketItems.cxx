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
  std::vector<std::string> keys;
  std::vector<std::string> values;
  std::vector<std::string> dataTypes;
  if(storeHash != "")
  {
    keys = {"store_alias", "store_hash"};
    values = {storeAlias, storeHash};
    dataTypes = {"String", "String"};
  }
  else 
  {
    keys = {"store_alias"};
    values = {storeAlias};
    dataTypes = {"String"};
  }
  std::string response = this->executeBash->returnResponse("https://api.bitskins.com/market/search/store", this->profile->user->getAPIKey(), keys, values, dataTypes);
  this->responseDisplayer->displayHttpResponse(this->em, response, input);
}


