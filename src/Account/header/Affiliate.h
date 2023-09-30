#include <cpr/cpr.h>
#include "../../CLI/header/UserCredentials.h"
#include "../../CLI//header/Help.h"
#include <cstdlib>
#include <stdlib.h>
#include <string>
#include <nlohmann/json.hpp>
#pragma once

class Affiliate
{
  public:
    UserCredentials* user;
    Help* help;
    
    Affiliate(UserCredentials* user, Help* help)
    {
      this->user = user;
      this->help = help;
    }

/*╭━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╮
  ┃                                                                              ┃
  ┃      Function: getAffiliateInfo() Description: This method will get the      ┃
  ┃    account's affiliation information. It will then print out the url and     ┃
  ┃      the text. NOTICE: If the api returns an empty string instead, that      ┃
  ┃   means the account is not affiliated. Therefore, the program will return    ┃
  ┃     no response. At last it will return a cpr::Response object with the      ┃
  ┃             request's information. Return: cpr::Response object              ┃
  ┃                                                                              ┃
  ╰━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╯
*/

    cpr::Response getAffiliateInfo(std::string input); 
};
