#include "../header/Profile.h"
#include <iostream>
#include <string>
using json = nlohmann::json;

/*╭━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╮
  ┃                                                                              ┃
  ┃     TODO: Maybe create a separate class for showing the error message if     ┃
  ┃              the request was not able to fulfill successfully.               ┃
  ┃                                                                              ┃
  ╰━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╯
*/


cpr::Response Profile::getCurrentSession(std::string input)
{
  if(input.find("-h") != std::string::npos)
  {
    this->help->showHelp(false, "-session -h");
  }
  cpr::Response session = cpr::Get(cpr::Url{"https://api.bitskins.com/account/profile/me"},  
                                   cpr::Header{{"x-apikey",this->user->getAPIKey()}});

  this->responseDisplayer->displayHttpResponse(this->em, session, input); 

  return session;
}

cpr::Response Profile::getAccountBalance(std::string input)
{
  if(input.find("-h") != std::string::npos)
  {
    this->help->showHelp(false, "-balance -h");
  }
  cpr::Response balance = cpr::Post(cpr::Url{"https://api.bitskins.com/account/profile/balance"},
                                    cpr::Header{{"x-apikey",this->user->getAPIKey()}},
                                    cpr::Body{});

  this->responseDisplayer->displayHttpResponse(this->em, balance, input);

  return balance;
}

void Profile::updateTradeLink(std::string input)
{
  ExecuteBash* eb = new ExecuteBash();
  if(input.find("-h") != std::string::npos)
  {
    this->help->showHelp(false, "-tradelink -h");
  }
  std::string Url;
  std::cout << "Please enter your updated trade link.\n";
  std::getline(std::cin, Url);
  json parsedUrl = {{"tradelink", Url}};
  eb->bashCurl("https://api.bitskins.com/account/profile/update_tradelink", this->user->getAPIKey(), "tradelink", Url); 
  //this->responseDisplayer->displayHttpResponse(this->em, tradeLink, input); 
}

cpr::Response Profile::updateAccount(std::string input)
{
  if(input.find("-h") != std::string::npos)
  {
    this->help->showHelp(false, "-updateaccount -h");
  }
  cpr::Response account = cpr::Post(cpr::Url{"https://api.bitskins.com/account/profile/update_tradelink"},
                                      cpr::Header{{"x-apikey", this->user->getAPIKey()}},
                                      cpr::Payload{{"tradelink", "https://steamcommunity.com/tradeoffer/new/?partner=1111&token=AAAA"}});

  this->responseDisplayer->displayHttpResponse(this->em, account, input); 
  return account;

}

/*                 ╭━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╮
                   ┃                                          ┃
                   ┃ WARNING: Untested. Try at your own risk. ┃
                   ┃                                          ┃
                   ╰━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╯
*/

cpr::Response Profile::blockAccount(std::string input)
{
  if(input.find("-h") != std::string::npos)
  {
    this->help->showHelp(false, "-block -h");
  }
  cpr::Response block = cpr::Post(cpr::Url{"https://api.bitskins.com/account/profile/block"},
                                      cpr::Header{{"x-apikey", this->user->getAPIKey()}},
                                      cpr::Body{});
  this->responseDisplayer->displayHttpResponse(this->em, block, input); 
  return block;
}

/*                ╭━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╮
                  ┃                                            ┃
                  ┃ TODO: Validate the input given by the user ┃
                  ┃                                            ┃
                  ╰━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╯
*/

UserCredentials* Profile::userLogin()
{
  UserCredentials* user = new UserCredentials();
  std::string input;
  std::cout << "Please insert your Bitskins API key:\n";
  std::getline(std::cin, input);
  user->setAPIKey(input);
  this->user = user;
  this->em = new ERRORMAP::errormap();
  return user;
}
