#ifndef APIKEY_H
#define APIKEY_H
#include <cpr/cpr.h>
#include "../../CLI//header/Help.h"
#include "../../CLI/header/Error.h"
#include "Profile.h"
#include <cstdlib>
#include <stdlib.h>
#include <string>
#include <nlohmann/json.hpp>
#include "../../CLI/header/ArgumentListener.h"

class APIKey
{
  public:
    Profile* profile;
    Help* help;
    ERRORMAP::errormap* em;
    ARGUMENTLISTENER_H::ArgumentListener* argumentListener;

    APIKey(Profile* profile)
    {
      this->profile = profile;
      this->help = this->profile->help;
      this->em = this->profile->em;
      this->argumentListener = new ArgumentListener();
    }
    CPR::Response disableAPIKey(std::string input);
};


