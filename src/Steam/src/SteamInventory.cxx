#include "../header/SteamInventory.h"
#include <iostream>
#include <string>

bool SteamInventory::getSteamInventory(std::string input)
{
  if(input.find("-h") != std::string::npos)
  {
    this->help->showHelp(false, input);
  }
  
  std::string appID;
  std::cout << "Please provide the appID:\ncs2: 730\ndota2: 570\ntf2: 440\nrust: 252490\n";
  std::getline(std::cin, appID);
  std::vector<std::string> keys = {"app_id"};
  std::vector<std::string> values = {appID};
  std::vector<std::string> dataTypes = {"Number"};
  this->executeBash->executeBashScript("https://api.bitskins.com/steam/inventory/list", this->profile->user->getAPIKey(), keys, values, dataTypes);
  return true;
}
