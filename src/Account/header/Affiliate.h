#ifndef AFFILIATE_H
#define AFFILIATE_H
#include <cpr/cpr.h>
#include "../../CLI//header/Help.h"
#include "../../CLI/header/Error.h"
#include "../../bash/header/ExecuteBash.h"
#include "../../CLI/header/ResponseDisplayer.h"
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
    ResponseDisplayer* responseDisplayer;
     
    Affiliate(Profile* profile)
    {
      this->profile = profile; 
      this->help = this->profile->help;
      this->em = this->profile->em;
      this->responseDisplayer = new ResponseDisplayer();
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


/*╭━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╮
  ┃                                                                              ┃
  ┃    Function: getListHistoricalRewards() Description: This method will get    ┃
  ┃     the account's historical rewards list. It will ask the user for the      ┃
  ┃       limit and the offset. The response will then be displayed if the       ┃
  ┃                         request was sent successful.                         ┃
  ┃                                                                              ┃
  ╰━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╯
*/

    void getListHistoricalRewards(std::string input);


/*╭━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╮
  ┃                                                                              ┃
  ┃      Function: setAffiliateCode() Description: This method will set the      ┃
  ┃      account's affiliate code. It will ask the user for a new affiliate      ┃
  ┃   code. Then the resquest will be sent. If the current affiliate code and    ┃
  ┃    the new affiliate code are the same, an error will be thrown from the     ┃
  ┃              rest-api's side. Else, response will be displayed.              ┃
  ┃                                                                              ┃
  ╰━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╯
*/

    void setAffiliateCode(std::string input);
};
#endif // !AFFILIATE_H
