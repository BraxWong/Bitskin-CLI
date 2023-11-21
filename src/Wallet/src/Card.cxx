#include "../header/Card.h"
#include <iostream>
#include <string>

cpr::Response Card::getCards(std::string input)
{
  if(input.find("-h") != std::string::npos)
  {
    this->help->showHelp(false, input);
  }
  cpr::Response response = cpr::Post(cpr::Url{"https://api.bitskins.com/wallet/deposit/unlimint/list_cards"},
                          cpr::Header{{"x-apikey",this->profile->user->getAPIKey()}},
                          cpr::Body{});

  this->responseDisplayer->displayHttpResponse(this->em, response, input);

  return response;
}

bool Card::depositCard(std::string input)
{
  if(input.find("-h") != std::string::npos)
  {
    this->help->showHelp(false, input);
  }

  std::string card_id, amount, securityCode;
  std::cout << "Please insert your card id:\n";
  std::getline(std::cin, card_id);
  std::cout << "Please insert the amount you wish to deposit:\n";
  std::getline(std::cin, card_id);
  std::cout << "Please insert the card's security code.\n";
  std::getline(std::cin, securityCode);

  std::vector<std::string> keys = {"card_id","amount","security_code"};
  std::vector<std::string> values = {card_id, amount, securityCode};
  std::vector<std::string> dataTypes = {"Number", "Number", "String"};

  this->executeBash->executeBashScript("https://api.bitskins.com/wallet/deposit/unlimint/card_deposit", this->profile->user->getAPIKey(), keys, values, dataTypes);

  return true;
}
