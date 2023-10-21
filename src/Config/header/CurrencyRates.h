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

    ~CurrencyRates()
    {
      delete this->responseDisplayer;
    }

/*╭━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╮
  ┃                                                                              ┃
  ┃      Function: getCurrencyRates() Description: This method will get the      ┃
  ┃    currency rates for different currency. It will then print out the url     ┃
  ┃      and the http request text. At last, it will return a cpr::Response      ┃
  ┃     object with the request's information. Return: cpr::Response object.     ┃
  ┃                                                                              ┃
  ╰━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╯
*/

    cpr::Response getCurrencyRates(std::string input);
}; 
#endif
