#include "../header/PlatformStatus.h"
#include <iostream>
#include <string>
using json = nlohmann::json;

cpr::Response PlatformStatus::getPlatformStatus(std::string input)
{
  if(input.find("-h") != std::string::npos)
  {
    this->help->showHelp(false, input);
  }

  cpr::Response response = cpr::Get(cpr::Url{"https://api.bitskins.com/config/status/get"},
                                    cpr::Header{{"x-apikey", this->profile->user->getAPIKey()}});

  this->responseDisplayer->displayHttpResponse(this->em, response.text, input);
  
  Global_Platform_Status buyOrder = static_cast<Global_Platform_Status>(json::parse(response.text)["buy_order"]);
  Global_Platform_Status instant_sell = static_cast<Global_Platform_Status>(json::parse(response.text)["instant_sell"]);
  Global_Platform_Status platform = static_cast<Global_Platform_Status>(json::parse(response.text)["platform"]);
  std::cout << "Buy Order Status: " <<getGlobalPlatformStatusString(buyOrder) << "\nInstant Sell Status: " 
    << getGlobalPlatformStatusString(instant_sell) << "\nPlatform Status: " << getGlobalPlatformStatusString(platform) << "\n"; 
  return response;
}

std::string getGlobalPlatformStatusString(Global_Platform_Status gps)
{
  switch (gps) 
  {
    case loading: return "loading";
    case offline: return "offline";
    case steam_down: return "steam_down";
    case active: return "active";
    default: return "Error";
  }
}
