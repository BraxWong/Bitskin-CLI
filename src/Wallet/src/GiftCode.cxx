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

  this->executeBash->executeBashScript("https://api.bitskins.com/wallet/deposit/gift_code/use", this->profile->user->getAPIKey(), keys, values, dataTypes);
}
