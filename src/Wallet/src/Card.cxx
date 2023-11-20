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
