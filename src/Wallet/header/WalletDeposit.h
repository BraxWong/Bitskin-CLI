#ifndef WALLETDEPOSIT_H
#define WALLETDEPOSIT_H
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

class WalletDespoit 
{
  public:
    Profile* profile;
    Help* help;
    ERRORMAP::errormap* em;
    ResponseDisplayer* responseDisplayer;
    ExecuteBash* executeBash; 

    WalletDespoit(Profile* profile)
    {
      this->profile = profile; 
      this->help = this->profile->help;
      this->em = this->profile->em;
      this->responseDisplayer = new ResponseDisplayer();
      this->executeBash = new ExecuteBash();
    }
  
    ~WalletDespoit()
    {
      delete this->responseDisplayer;
      delete this->executeBash;
    }
  
    bool depositBinance(std::string input);

    cpr::Response getCryptoAddress(std::string input);

    bool getLitecoinAddress(std::string input);
};

#endif

