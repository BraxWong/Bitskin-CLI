#ifndef AFFILIATE_H
#define AFFILIATE_H
#include <cpr/cpr.h>
#include "../../CLI//header/Help.h"
#include "../../CLI/header/Error.h"
#include "Profile.h"
#include <cstdlib>
#include <stdlib.h>
#include <string>
#include <nlohmann/json.hpp>
class Affiliate
{
    public:
      Profile* profile;
      Help* help;
      ERRORMAP::errormap* em;
    
      Affiliate(Profile* profile)
      {
        this->profile = profile; 
        this->help = this->profile->help;
        this->em = this->profile->em;
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
  cpr::Response claimMoney(std::string input);
};
#endif // !AFFILIATE_H
