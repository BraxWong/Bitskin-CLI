#ifndef CURRENCYRATES_H
#define CURRENCYRATES_H
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

class CurrencyRates 
{
  public:
    Profile* profile;
    Help* help;
    ERRORMAP::errormap* em;
    ResponseDisplayer* responseDisplayer;

    CurrencyRates(Profile* profile)
    {
      this->profile = profile;
      this->help = this->profile->help;
      this->em = this->profile->em;
      this->responseDisplayer = new ResponseDisplayer();
    }

    cpr::Response getCurrencyRates(std::string input);
}; 
#endif
