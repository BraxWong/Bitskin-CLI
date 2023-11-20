#ifndef CARD_H
#define CARD_H
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

class Card 
{
  public:
    Profile* profile;
    Help* help;
    ERRORMAP::errormap* em;
    ResponseDisplayer* responseDisplayer;
    ExecuteBash* executeBash; 

    Card(Profile* profile)
    {
      this->profile = profile; 
      this->help = this->profile->help;
      this->em = this->profile->em;
      this->responseDisplayer = new ResponseDisplayer();
      this->executeBash = new ExecuteBash();
    }
  
    ~Card()
    {
      delete this->responseDisplayer;
      delete this->executeBash;
    }

    cpr::Response getCards(std::string input);
}; 

#endif // DEBUG


