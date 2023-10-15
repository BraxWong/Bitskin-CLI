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

void Affiliate::getListHistoricalRewards(std::string input)
{
  ExecuteBash* eb = new ExecuteBash();
  if(input.find(" -h") != std::string::npos)
  {
    this->help->showHelp(false, input);
  }
  std::string limit, offset;
  std::cout << "Please enter your limit\n";
  std::getline(std::cin, limit);
  std::cout << "Please enter your offset\n";
  std::getline(std::cin, offset);
  std::vector<std::string> keys = {"limit","offset"};
  std::vector<std::string> values = {limit, offset};
  std::vector<std::string> dataTypes = {"Numbers","Numbers"};
  eb->executeBashScript("https://api.bitskins.com/account/affiliate/history", this->profile->user->getAPIKey(), keys, values, dataTypes);
}

void Affiliate::setAffiliateCode(std::string input)
{
  ExecuteBash* eb = new ExecuteBash();
  if(input.find("-h") != std::string::npos)
  {
    this->help->showHelp(false, input);
  }
  std::string code;
  std::cout << "Please enter your affiliation code.\n";
  std::getline(std::cin, code);
  std::vector<std::string> keys = {"code"};
  std::vector<std::string> values = {code};
  std::vector<std::string> dataTypes = {"String"};
  eb->executeBashScript("https://api.bitskins.com/account/affiliate/set_code", this->profile->user->getAPIKey(), keys, values, dataTypes);
}
