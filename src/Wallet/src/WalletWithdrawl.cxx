#include "../header/WalletWithdrawl.h"
#include <iostream>
#include <string>
#include <vector>

bool WalletWithdrawl::withdrawlBitcoin(std::string input)
{
  if(input.find("-h") != std::string::npos)
  {
    this->help->showHelp(false, input);
  }
 
  std::string amount, address, twoCode;

  std::cout << "Please provide the amount you would like to withdrawl:\n";
  std::getline(std::cin, amount);
  std::cout << "Please provide your bitcoin address:\n";
  std::getline(std::cin, address);
  std::cout << "Please provide your 2 factor authentication code:\n";
  std::getline(std::cin, twoCode);

  std::vector<std::string> keys = {"amount","address","twofa_code""};
  std::vector<std::string> values = {amount, address, twoCode};
  std::vector<std::string> dataTypes = {"Number", "String", "String"};

  this->executeBash->executeBashScript("https://api.bitskins.com/wallet/withdraw/crypto/litecoin",this->profile->user->getAPIKey(), keys, values, dataTypes);

  return true;

}


bool WalletWithdrawl::withdrawlLitecoin(std::string input)
{
  if(input.find("-h") != std::string::npos)
  {
    this->help->showHelp(false, input);
  }
 
  std::string amount, address, twoCode;

  std::cout << "Please provide the amount you would like to withdrawl:\n";
  std::getline(std::cin, amount);
  std::cout << "Please provide your litecoin address:\n";
  std::getline(std::cin, address);
  std::cout << "Please provide your 2 factor authentication code:\n";
  std::getline(std::cin, twoCode);

  std::vector<std::string> keys = {"amount","address","twofa_code""};
  std::vector<std::string> values = {amount, address, twoCode};
  std::vector<std::string> dataTypes = {"Number", "String", "String"};

  this->executeBash->executeBashScript("https://api.bitskins.com/wallet/withdraw/crypto/bitcoin",this->profile->user->getAPIKey(), keys, values, dataTypes);

  return true;
}

bool WalletWithdrawl::withdrawlEthereum(std::string input)
{
  if(input.find("-h") != std::string::npos)
  {
    this->help->showHelp(false, input);
  }
 
  std::string amount, address, twoCode;

  std::cout << "Please provide the amount you would like to withdrawl:\n";
  std::getline(std::cin, amount);
  std::cout << "Please provide your ethereum address:\n";
  std::getline(std::cin, address);
  std::cout << "Please provide your 2 factor authentication code:\n";
  std::getline(std::cin, twoCode);

  std::vector<std::string> keys = {"amount","address","twofa_code""};
  std::vector<std::string> values = {amount, address, twoCode};
  std::vector<std::string> dataTypes = {"Number", "String", "String"};

  this->executeBash->executeBashScript("https://api.bitskins.com/wallet/withdraw/crypto/ethereum",this->profile->user->getAPIKey(), keys, values, dataTypes);

  return true;
}

bool WalletWithdrawl::withdrawlBinance(std::string input)
{
  if(input.find("-h") != std::string::npos)
  {
    this->help->showHelp(false, input);
  }
 
  std::string amount, receiver, twoCode;

  std::cout << "Please provide the amount you would like to withdrawl:\n";
  std::getline(std::cin, amount);
  std::cout << "Please provide your binance receiver:\n";
  std::getline(std::cin, receiver);
  std::cout << "Please provide your 2 factor authentication code:\n";
  std::getline(std::cin, twoCode);

  std::vector<std::string> keys = {"amount","receiver","twofa_code""};
  std::vector<std::string> values = {amount, receiver, twoCode};
  std::vector<std::string> dataTypes = {"Number", "String", "String"};

  this->executeBash->executeBashScript("https://api.bitskins.com/wallet/withdraw/binancepay/create",this->profile->user->getAPIKey(), keys, values, dataTypes);

  return true;
}
