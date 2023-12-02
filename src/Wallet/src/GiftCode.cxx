#include "../header/GiftCode.h"
#include <iostream>
#include <string>

bool GiftCode::useGiftCode(std::string input)
{
  if(input.find("-h") != std::string::npos)
  {
    this->help->showHelp(false, input);
  }

  std::string giftCode;
  std::cout << "Please enter your gift code:\n";
  std::getline(std::cin, giftCode);

  std::vector<std::string> keys = {"code"};
  std::vector<std::string> values = {giftCode};
  std::vector<std::string> dataTypes = {"String"};

  std::string response = this->executeBash->returnResponse("https://api.bitskins.com/wallet/deposit/gift_code/use", this->profile->user->getAPIKey(), keys, values, dataTypes);
  this->responseDisplayer->displayHttpResponse(this->em, response, input);
  return true;
}

cpr::Response GiftCode::getUsedGiftCodes(std::string input)
{
  if(input.find("-h") != std::string::npos)
  {
    this->help->showHelp(false, input);
  }
  cpr::Response response = cpr::Post(cpr::Url{"https://api.bitskins.com/wallet/deposit/gift_code/list_used"},
                          cpr::Header{{"x-apikey",this->profile->user->getAPIKey()}},
                          cpr::Body{});

  this->responseDisplayer->displayHttpResponse(this->em, response.text, input);
  return response;
}
