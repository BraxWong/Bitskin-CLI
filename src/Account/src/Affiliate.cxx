#include "../header/Affiliate.h"
#include <iostream>
#include <string>
using json = nlohmann::json;


cpr::Response Affiliate::getAffiliateInfo(std::string input)
{
  if(input.find("-h") != std::string::npos)
  {
    this->help->showHelp(false, input);
  }
  cpr::Response affiliate_info = cpr::Post(cpr::Url{"https://api.bitskins.com/account/affiliate/me"}, 
                                 cpr::Authentication{this->profile->user->getUsername(), this->profile->user->getPassword(), cpr::AuthMode::DIGEST},
                                 cpr::Header{{"x-apikey",this->profile->user->getAPIKey()}},
                                 cpr::Body{});
  if(affiliate_info.text[0] == '{')
  {
    json j = json::parse(affiliate_info.text);
    if(!this->em->checkErrorResponse(j) && !this->argumentListener->displayArgumentInfoOnly(j, input))
    {
      std::cout << affiliate_info.url << "\n" << json::parse(affiliate_info.text).dump(4) << "\n";
    }
  }
  else 
  {
    std::cout << "No response.\n";
  }
  return affiliate_info;
}

cpr::Response Affiliate::claimMoney(std::string input)
{
  if(input.find("-h") != std::string::npos)
  {
    this->help->showHelp(false, input);
  }
  cpr::Response response = cpr::Post(cpr::Url{"https://api.bitskins.com/account/affiliate/transfer_money"}, 
                                 cpr::Authentication{this->profile->user->getUsername(), this->profile->user->getPassword(), cpr::AuthMode::DIGEST},
                                 cpr::Header{{"x-apikey",this->profile->user->getAPIKey()}},
                                 cpr::Body{});
  json j = json::parse(response.text);
  if(!this->em->checkErrorResponse(j) && !this->argumentListener->displayArgumentInfoOnly(j, input))
  {
    std::cout << response.url << "\n" << json::parse(response.text).dump(4) << "\n";
  }
  return response;
}
