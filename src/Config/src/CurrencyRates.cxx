#include "../header/CurrencyRates.h"
#include <iostream>
#include <string>
using json = nlohmann::json;

cpr::Response CurrencyRates::getCurrencyRates(std::string input)
{
  if(input.find("-h") != std::string::npos)
  {
    this->help->showHelp(false, input);
  }

  cpr::Response response = cpr::Get(cpr::Url{"https://api.bitskins.com/config/currency/list"},
                                    cpr::Header{{"x-apikey", this->profile->user->getAPIKey()}});

  this->responseDisplayer->displayHttpResponse(this->em, response, input);
  return response;
}
