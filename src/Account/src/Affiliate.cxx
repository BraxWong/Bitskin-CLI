#include "../header/Affiliate.h"
#include <iostream>
#include <string>
using json = nlohmann::json;


cpr::Response Affiliate::getAffiliateInfo(std::string input)
{
  if(input.find("-h") != std::string::npos)
  {
    this->help->showHelp(false,input);
  }
  cpr::Response affiliate_info = cpr::Post(cpr::Url{"https://api.bitskins.com/account/affiliate/me"}, 
                                 cpr::Authentication{this->user->getUsername(), this->user->getPassword(), cpr::AuthMode::DIGEST},
                                 cpr::Header{{"x-apikey",this->user->getAPIKey()}},
                                 cpr::Body{});
  if(affiliate_info.text[0] == '{')
  {
    std::cout << affiliate_info.url << "\n" << json::parse(affiliate_info.text).dump(4) << "\n";
  }
  else 
  {
    std::cout << "No response.\n";
  }
  return affiliate_info;

}
