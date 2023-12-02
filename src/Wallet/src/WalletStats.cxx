#include "../header/WalletStats.h"
#include <iostream>
#include <string>

cpr::Response WalletStats::getWalletStats(std::string input)
{
  if(input.find("-h") != std::string::npos)
  {
    this->help->showHelp(false, input);
  }
   
  cpr::Response session = cpr::Get(cpr::Url{"https://api.bitskins.com/wallet/stats/get"},  
                                   cpr::Header{{"x-apikey",this->profile->user->getAPIKey()}});

  this->responseDisplayer->displayHttpResponse(this->em, session.text, input); 

  return session;

}

cpr::Response WalletStats::getKYCLimits(std::string input)
{
  if(input.find("-h") != std::string::npos)
  {
    this->help->showHelp(false, input);
  }
  cpr::Response session = cpr::Get(cpr::Url{"https://api.bitskins.com/wallet/stats/get_kyc_limit"},  
                                   cpr::Header{{"x-apikey",this->profile->user->getAPIKey()}});

  this->responseDisplayer->displayHttpResponse(this->em, session.text, input); 

  return session;

}
