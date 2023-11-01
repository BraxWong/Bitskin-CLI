#ifndef WALLETSTATS_H
#define WALLETSTATS_H
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

class WalletStats 
{
  public:
    Profile* profile;
    Help* help;
    ERRORMAP::errormap* em;
    ResponseDisplayer* responseDisplayer;
    ExecuteBash* executeBash; 

    WalletStats(Profile* profile)
    {
      this->profile = profile; 
      this->help = this->profile->help;
      this->em = this->profile->em;
      this->responseDisplayer = new ResponseDisplayer();
      this->executeBash = new ExecuteBash();
    }
  
    ~WalletStats()
    {
      delete this->responseDisplayer;
      delete this->executeBash;
    }


/*╭━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╮
  ┃                                                                              ┃
  ┃   Function: getWalletStats() Description: This method will get the user's    ┃
  ┃                            Bitskin wallet stats.                             ┃
  ┃                                                                              ┃
  ╰━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╯
*/

    cpr::Response getWalletStats(std::string input);


/*╭━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╮
  ┃                                                                              ┃
  ┃    Function: getKYCLimits() Description: This method will get the user's     ┃
  ┃                             Bitskin KYC Limits.                              ┃
  ┃                                                                              ┃
  ╰━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╯
*/

    cpr::Response getKYCLimits(std::string input);
};

#endif

