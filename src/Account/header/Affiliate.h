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
#include "../../CLI/header/ArgumentListener.h"

class Affiliate
{
  public:
    Profile* profile;
    Help* help;
    ERRORMAP::errormap* em;
    ARGUMENTLISTENER_H::ArgumentListener* argumentListener;
     
    Affiliate(Profile* profile)
    {
      this->profile = profile; 
      this->help = this->profile->help;
      this->em = this->profile->em;
      this->argumentListener = new ArgumentListener();
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


/*╭━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╮
  ┃                                                                              ┃
  ┃      Function: claimMoeny() Description: This method will give you the       ┃
  ┃         option to claim the money that was earned from the Bitskins'         ┃
  ┃   affiliation program. Notice: If the user has not activated the bitskins    ┃
  ┃                  affiliation program, an error will return.                  ┃
  ┃                                                                              ┃
  ╰━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╯
*/

    cpr::Response claimMoney(std::string input);
};
#endif // !AFFILIATE_H