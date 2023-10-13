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
#include "../../CLI/header/ResponseDisplayer.h"

class APIKey
{
  public:
    Profile* profile;
    Help* help;
    ERRORMAP::errormap* em;
    ResponseDisplayer* responseDisplayer;

    APIKey(Profile* profile)
    {
      this->profile = profile;
      this->help = this->profile->help;
      this->em = this->profile->em;
      this->responseDisplayer = new ResponseDisplayer();
    }


/*╭━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╮
  ┃                                                                              ┃
  ┃     Function: disableAPIKey() Description: This function takes a string      ┃
  ┃    input. It will display the user's Bitskins' APIKey. It will then print    ┃
  ┃            out the url and the text. Return: cpr::Response object            ┃
  ┃                                                                              ┃
  ╰━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╯
*/

    cpr::Response disableAPIKey(std::string input);

};
#endif

