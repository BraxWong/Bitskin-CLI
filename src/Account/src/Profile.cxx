#include "../header/Profile.h"
#include <iostream>
#include <string>
using json = nlohmann::json;

/*╭━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╮
  ┃ ┃ ┃     TODO: Maybe create a separate class for showing the error message if
  ┃ ┃              the request was not able to fulfill successfully. ┃ ┃ ┃
  ╰━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╯
*/

cpr::Response Profile::getCurrentSession(std::string input) {
  if (input.find("-h") != std::string::npos) {
    this->help->showHelp(false, "-session -h");
  }
  cpr::Response session =
      cpr::Get(cpr::Url{"https://api.bitskins.com/account/profile/me"},
               cpr::Header{{"x-apikey", this->user->getAPIKey()}});

  this->responseDisplayer->displayHttpResponse(this->em, session.text, input);

  return session;
}

cpr::Response Profile::getAccountBalance(std::string input) {
  if (input.find("-h") != std::string::npos) {
    this->help->showHelp(false, "-balance -h");
  }
  cpr::Response balance = cpr::Post(
      cpr::Url{"https://api.bitskins.com/account/profile/balance"},
      cpr::Header{{"x-apikey", this->user->getAPIKey()}}, cpr::Body{});

  this->responseDisplayer->displayHttpResponse(this->em, balance.text, input);

  return balance;
}

void Profile::updateTradeLink(std::string input) {
  std::cout << "You can find your trade link in "
               "http://steamcommunity.com/my/tradeoffers/privacy\n";
  if (input.find("-h") != std::string::npos) {
    this->help->showHelp(false, "-tradelink -h");
  }
  std::string Url;
  std::cout << "Please enter your updated trade link.\n";
  std::getline(std::cin, Url);
  std::vector<std::string> keys = {"tradelink"};
  std::vector<std::string> values = {Url};
  std::vector<std::string> dataTypes = {"String"};
  std::string response = this->executeBash->returnResponse(
      "https://api.bitskins.com/account/profile/update_tradelink",
      this->user->getAPIKey(), keys, values, dataTypes);
  this->responseDisplayer->displayHttpResponse(this->em, response, input);
}

cpr::Response Profile::updateAccount(std::string input) {
  if (input.find("-h") != std::string::npos) {
    this->help->showHelp(false, "-updateaccount -h");
  }
  cpr::Response account = cpr::Post(
      cpr::Url{"https://api.bitskins.com/account/profile/update_tradelink"},
      cpr::Header{{"x-apikey", this->user->getAPIKey()}},
      cpr::Payload{{"tradelink", "https://steamcommunity.com/tradeoffer/new/"
                                 "?partner=1111&token=AAAA"}});

  this->responseDisplayer->displayHttpResponse(this->em, account.text, input);
  return account;
}

/*                 ╭━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╮
                   ┃                                          ┃
                   ┃ WARNING: Untested. Try at your own risk. ┃
                   ┃                                          ┃
                   ╰━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╯
*/

cpr::Response Profile::blockAccount(std::string input) {
  if (input.find("-h") != std::string::npos) {
    this->help->showHelp(false, "-block -h");
  }
  cpr::Response block = cpr::Post(
      cpr::Url{"https://api.bitskins.com/account/profile/block"},
      cpr::Header{{"x-apikey", this->user->getAPIKey()}}, cpr::Body{});
  this->responseDisplayer->displayHttpResponse(this->em, block.text, input);
  return block;
}

UserCredentials* Profile::userLogin()
{
  UserCredentials* user = new UserCredentials();
  std::string apiKey;
  std::string authToken;
  bool apiSet = false;
  while(apiSet == false) {
    std::cout << "Please insert your valid Bitskins API key:\n";
    std::getline(std::cin, apiKey);
    apiSet = user->setAPIKey(apiKey);
  }  
  //TODO: the Bitskins Auth Token is not actually used anywhere in the codebase. Consider removing it.
  std::cout << "Please insert your Bitskins Auth Token (Optional):\n";
  std::getline(std::cin, authToken);
  user->setAuthToken(authToken);
  this->user = user;
  this->em = new ERRORMAP::errormap();
  return user;
}
