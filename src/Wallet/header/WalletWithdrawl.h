#ifndef WALLETWITHDRAWL_H
#define WALLETWITHDRAWL_H
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

class WalletWithdrawl 
{
  public:
    Profile* profile;
    Help* help;
    ERRORMAP::errormap* em;
    ResponseDisplayer* responseDisplayer;
    ExecuteBash* executeBash; 

    WalletWithdrawl(Profile* profile)
    {
      this->profile = profile; 
      this->help = this->profile->help;
      this->em = this->profile->em;
      this->responseDisplayer = new ResponseDisplayer();
      this->executeBash = new ExecuteBash();
    }
  
    ~WalletWithdrawl()
    {
      delete this->responseDisplayer;
      delete this->executeBash;
    }



/*╭━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╮
  ┃                                                                              ┃
  ┃                         Function: withdrawlBitcoin()                         ┃
  ┃      Param: input string which contains the command and optionally the       ┃
  ┃                           argument for the command                           ┃
  ┃    Description: This method allows users to withdraw Bitskin wallet fund     ┃
  ┃                           to their Bitcoin Account                           ┃
  ┃       Return: boolean which determines if the operation was successful       ┃
  ┃                                                                              ┃
  ╰━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╯
*/

    bool withdrawlBitcoin(std::string input);


/*╭━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╮
  ┃                                                                              ┃
  ┃                        Function: withdrawlLitecoin()                         ┃
  ┃      Param: input string which contains the command and optionally the       ┃
  ┃                           argument for the command                           ┃
  ┃    Description: This method allows users to withdraw Bitskin wallet fund     ┃
  ┃                          to their Litecoin Account                           ┃
  ┃      Return: boolean which determines if the operation was successful.       ┃
  ┃                                                                              ┃
  ┃                                                                              ┃
  ╰━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╯
*/

    bool withdrawlLitecoin(std::string input);


/*╭━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╮
  ┃                                                                              ┃
  ┃                        Function: withdrawlEthereum()                         ┃
  ┃      Param: input string which contains the command and optionally the       ┃
  ┃                           argument for the command                           ┃
  ┃    Description: This method allows users to withdraw Bitskin wallet fund     ┃
  ┃                          to their Ethereum Account                           ┃
  ┃      Return: boolean which determines if the operation was successful.       ┃
  ┃                                                                              ┃
  ╰━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╯
*/

    bool withdrawlEthereum(std::string input);


/*╭━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╮
  ┃                                                                              ┃
  ┃                         Function: withdrawlBinance()                         ┃
  ┃      Param: input string which contains the command and optionally the       ┃
  ┃                           argument for the command                           ┃
  ┃    Description: This method allows users to withdraw Bitskin wallet fund     ┃
  ┃                       to their Binance account.                              ┃
  ┃      Return: boolean which determines if the operation was successful.       ┃
  ┃                                                                              ┃
  ╰━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╯
*/

    bool withdrawlBinance(std::string input);


/*╭━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╮
  ┃                                                                              ┃
  ┃                          Function: withdrawlVisa()                           ┃
  ┃      Param: input string which contains the command and optionally the       ┃
  ┃                           argument for the command                           ┃
  ┃    Description: This method allows users to withdraw Bitskin wallet fund     ┃
  ┃                          to their Visa credit card.                          ┃
  ┃      Return: boolean which determines if the operation was successful.       ┃
  ┃                                                                              ┃
  ╰━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╯
*/

    bool withdrawlVisa(std::string input);
};

#endif

