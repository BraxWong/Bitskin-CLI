#include <iostream>
#include <string>
#include "../header/APIKey.h"
using json = nlohmann::json;

//                 ╭-------------------------------------------╮
//                 |                                           |
//                 | This is untested so try at your own risk. |
//                 |                                           |
//                 ╰-------------------------------------------╯

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

cpr::Response APIKey::createAPIKey(std::string input)
{
  if(input.find("-h") != std::string::npos)
  {
    this->help->showHelp(false, input);
  }

//        ╭-------------------------------------------------------------╮
//        |                                                             |
//        | User did not provide their authentication token upon login. |
//        |                                                             |
//        ╰-------------------------------------------------------------╯

  while(this->profile->user->getAuthToken().length() == 0) {
    std::string authToken;
    std::cout << "Please insert your authentication token:\n";
    std::getline(std::cin, authToken);
    if(authToken.length() != 0){
      this->profile->user->setAuthToken(authToken);
      break;
    }
  }
  cpr::Response response = cpr::Post(cpr::Url{"https://api.bitskins.com/account/token/create"},
                                     cpr::Header{{"x-auth-token", this->profile->user->getAuthToken()}},
                                     cpr::Body{});

  this->responseDisplayer->displayHttpResponse(this->em, response.text, input); 
  return response;
}
