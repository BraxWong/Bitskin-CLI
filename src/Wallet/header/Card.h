#ifndef CARD_H
#define CARD_H
#include <cpr/cpr.h>
#include "../../CLI//header/Help.h"
#include "../../CLI/header/Error.h"
#include "../../bash/header/ExecuteBash.h"
#include "../../CLI/header/ResponseDisplayer.h"
#include "../../Account/header/Profile.h"
#include "WalletStats.h"
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


/*╭━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╮
  ┃                                                                              ┃
  ┃                             Function: getCards()                             ┃
  ┃        Description: This method allows users to retrieve credit cards        ┃
  ┃          information that they have stored on their Bitskin Account          ┃
  ┃                         Return: cpr::Response object                         ┃
  ┃                                                                              ┃
  ╰━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╯
*/

    cpr::Response getCards(std::string input);


/*╭━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╮
  ┃                                                                              ┃
  ┃                           Function: depositCard()                            ┃
  ┃      Description: This method allows users to store their credit cards       ┃
  ┃detail on Bitskin so they can use it to add fund to their Bitskin WalletStats ┃
  ┃       Return: boolean which determines if the operation was successful       ┃
  ┃                                                                              ┃
  ╰━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╯
*/

    bool depositCard(std::string input);
}; 

#endif // DEBUG


