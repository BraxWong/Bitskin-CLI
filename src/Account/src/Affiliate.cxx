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
                                 cpr::Header{{"x-apikey",this->profile->user->getAPIKey()}},
                                 cpr::Body{});
  this->responseDisplayer->displayHttpResponse(this->em, affiliate_info, input); 
  return affiliate_info;
}

cpr::Response Affiliate::claimMoney(std::string input)
{
  if(input.find("-h") != std::string::npos)
  {
    this->help->showHelp(false, input);
  }
  cpr::Response response = cpr::Post(cpr::Url{"https://api.bitskins.com/account/affiliate/transfer_money"}, 
                                 cpr::Header{{"x-apikey",this->profile->user->getAPIKey()}},
                                 cpr::Body{});
  this->responseDisplayer->displayHttpResponse(this->em, response, input); 
  return response;
}

cpr::Response Affiliate::getListHistoricalRewards(std::string input)
{
  if(input.find(" -h") != std::string::npos)
  {
    this->help->showHelp(false, input);
  }
  cpr::Response response = cpr::Post(cpr::Url{"https://api.bitskins.com/account/affiliate/history"},
                                     cpr::Header{{"x-apikey",this->profile->user->getAPIKey()}},
                                     cpr::Payload{{"limit", "30"}, {"offset", "0"}});
  this->responseDisplayer->displayHttpResponse(this->em, response, input);
  return response;
}

