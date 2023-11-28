#ifndef WALLETWITHDRAWL_H
#define WALLETWITHDRAWL_H
#include <cpr/cpr.h>
#include "../../CLI//header/Help.h"
#include "../../CLI/header/Error.h"
#include "../../bash/header/ExecuteBash.h"
#include "../../CLI/header/ResponseDisplayer.h"
#include "../../Account/header/Profile.h"
#include <cstdlib>
#include <stdlib.h>
#include <string>
#include <nlohmann/json.hpp>
#include <vector>

class WalletWithdrawl 
{
  public:
    Profile* profile;
    Help* help;
    ERRORMAP::errormap* em;
    ResponseDisplayer* responseDisplayer;
    ExecuteBash* executeBash; 

    WalletWithdrawl(Profile* profile)
    {
      this->profile = profile; 
      this->help = this->profile->help;
      this->em = this->profile->em;
      this->responseDisplayer = new ResponseDisplayer();
      this->executeBash = new ExecuteBash();
    }
  
    ~WalletWithdrawl()
    {
      delete this->responseDisplayer;
      delete this->executeBash;
    }


    bool withdrawlBitcoin(std::string input);

    bool withdrawlLitecoin(std::string input);

    bool withdrawlEthereum(std::string input);
};

#endif

