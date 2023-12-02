#include "../header/SteamTrades.h"
#include <iostream>
#include <string>

bool SteamTrades::getSteamTrades(std::string input)
{
  if(input.find("-h") != std::string::npos)
  {
    this->help->showHelp(false, input);
  }
  std::string appID, limit, offset;
  std::cout << "Please provide the appID:\ncs2: 730\ndota2: 570\ntf2: 440\nrust: 252490\n";
  std::getline(std::cin, appID);
  std::cout << "Please provide the limit:\n";
  std::getline(std::cin, limit);
  std::cout << "Please provide the offset:\n";
  std::getline(std::cin, offset);
  std::vector<std::string> keys = {"app_id", "limit", "offset"};
  std::vector<std::string> values = {appID, limit, offset};
  std::vector<std::string> dataTypes = {"Number", "Number", "Number"};
  std::string response = this->executeBash->returnResponse("https://api.bitskins.com/steam/trade/list", this->profile->user->getAPIKey(), keys, values, dataTypes);
  this->responseDisplayer->displayHttpResponse(this->em, response, input);
  return true;
}

bool SteamTrades::getActiveSteamTrades(std::string input)
{
  if(input.find("-h") != std::string::npos)
  {
    this->help->showHelp(false, input);
  }
  std::string appID, limit, offset;
  std::cout << "Please provide the appID:\ncs2: 730\ndota2: 570\ntf2: 440\nrust: 252490\n";
  std::getline(std::cin, appID);
  std::cout << "Please provide the limit:\n";
  std::getline(std::cin, limit);
  std::cout << "Please provide the offset:\n";
  std::getline(std::cin, offset);
  std::vector<std::string> keys = {"app_id", "limit", "offset"};
  std::vector<std::string> values = {appID, limit, offset};
  std::vector<std::string> dataTypes = {"Number", "Number", "Number"};
  std::string response = this->executeBash->returnResponse("https://api.bitskins.com/steam/trade/active", this->profile->user->getAPIKey(), keys, values, dataTypes);
  this->responseDisplayer->displayHttpResponse(this->em, response, input);
  return true;
}

cpr::Response SteamTrades::getSteamTradeHash(std::string input)
{
  if(input.find("-h ") != std::string::npos)
  {
    this->help->showHelp(false, input);
  }

  cpr::Response session = cpr::Get(cpr::Url{"https://api.bitskins.com/trade/active_hash"},  
                                   cpr::Header{{"x-apikey",this->profile->user->getAPIKey()}});

  this->responseDisplayer->displayHttpResponse(this->em, session.text, input); 

  return session;
}

