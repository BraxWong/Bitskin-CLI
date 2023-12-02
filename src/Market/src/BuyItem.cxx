#include "../header/BuyItem.h"
#include <iostream>
#include <string>

void BuyItem::buySingleItem(std::string input)
{
  if(input.find("-h") != std::string::npos)
  {
    this->help->showHelp(false, input);
  }
  std::string appID, skinID, maxPrice;
  std::cout << "Please provide the appID:\ncs2: 730\ndota2: 570\ntf2: 440\nrust: 252490\n";
  std::getline(std::cin, appID);
  std::cout << "Please provide the skinID:\n";
  std::getline(std::cin, skinID);
  std::cout << "Please provide the max price you would purchase that item for:\n";
  std::getline(std::cin, maxPrice);
  std::vector<std::string> keys = {"app_id","id","max_price"};
  std::vector<std::string> values = {appID, skinID, maxPrice};
  std::vector<std::string> dataTypes = {"Number","String","Number"};

  std::string response = this->executeBash->returnResponse("https://api.bitskins.com/market/buy/single", this->profile->user->getAPIKey(), keys, values, dataTypes);
  this->responseDisplayer->displayHttpResponse(this->em, response, input);
}

