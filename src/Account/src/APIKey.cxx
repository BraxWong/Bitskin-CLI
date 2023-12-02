#include <iostream>
#include <string>
#include "../header/APIKey.h"
using json = nlohmann::json;

cpr::Response APIKey::disableAPIKey(std::string input)
{
  if(input.find("-h") != std::string::npos)
  {
    this->help->showHelp(false, input);
  }
  cpr::Response response =  cpr::Post(cpr::Url{"https://api.bitskins.com/account/apikey/disable"}, 
                                 cpr::Header{{"x-apikey",this->profile->user->getAPIKey()}},
                                 cpr::Body{});

  this->responseDisplayer->displayHttpResponse(this->em, response.text, input); 
  return response;
}
