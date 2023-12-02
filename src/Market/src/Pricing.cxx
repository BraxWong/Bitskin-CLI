#include "../header/Pricing.h"
#include <iostream>
#include <string>
#include <vector>

void Pricing::getSales(std::string input)
{
  if(input.find("-h") != std::string::npos)
  {
    this->help->showHelp(false, input);
  }

  std::string appID, skinID;
  std::cout << "Please provide the appID:\ncs2: 730\ndota2: 570\ntf2: 440\nrust: 252490\n";
  std::getline(std::cin, appID);
  std::cout << "Please provide the skinID:\n";
  std::getline(std::cin, skinID);
  std::vector<std::string> keys = {"app_id", "skin_id"};
  std::vector<std::string> values = {appID, skinID};
  std::vector<std::string> dataTypes = {"Number", "Number"};
  std::string response = this->executeBash->returnResponse("https://api.bitskins.com/market/pricing/list", this->profile->user->getAPIKey(), keys, values, dataTypes);
  this->responseDisplayer->displayHttpResponse(this->em, response, input);
}


void Pricing::getPricingSummary(std::string input)
{
  if(input.find("-h") != std::string::npos)
  {
    this->help->showHelp(false, input);
  }
  std::string appID, skinID, date_from, date_to;
  std::cout << "Please provide the appID:\ncs2: 730\ndota2: 570\ntf2: 440\nrust: 252490\n";
  std::getline(std::cin, appID);
  std::cout << "Please provide the skinID:\n";
  std::getline(std::cin, skinID);
  std::cout << "Please provide the starting search date for sales stat:(YYYY-MM-DD)\n";
  std::getline(std::cin, date_from);
  std::cout << "Please provide the ending search date for sales stat:(YYYY-MM-DD)\n";
  std::getline(std::cin, date_to);
  std::vector<std::string> keys = {"app_id", "skin_id", "date_from", "date_to"};
  std::vector<std::string> values = {appID, skinID, date_from, date_to};
  std::vector<std::string> dataTypes = {"Number","Number","String","String"};
  std::string response = this->executeBash->returnResponse("https://api.bitskins.com/market/pricing/summary", this->profile->user->getAPIKey(), keys, values, dataTypes);
  this->responseDisplayer->displayHttpResponse(this->em, response, input);
}
