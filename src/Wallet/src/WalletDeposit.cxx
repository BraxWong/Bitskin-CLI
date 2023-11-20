#include "../header/WalletDeposit.h"
#include <iostream>
#include <string>

bool WalletDespoit::depositBinance(std::string input)
{
  if(input.find("-h") != std::string::npos)
  {
    this->help->showHelp(false, input);
  }

  std::string amount;
  std::cout << "Please select the amount you want to deposit\n";
  std::getline(std::cin, amount);
  std::vector<std::string> keys = {"amount"};
  std::vector<std::string> values = {amount};
  std::vector<std::string> dataTypes = {"Number"};

  this->executeBash->executeBashScript("https://api.bitskins.com/wallet/deposit/binancepay/create", this->profile->user->getAPIKey(), keys, values, dataTypes);

  return true;
}

bool WalletDespoit::depositZen(std::string input)
{
  if(input.find("-h") != std::string::npos)
  {
    this->help->showHelp(false, input);
  }

  std::string amount;
  std::cout << "Please select the amount you want to deposit\n";
  std::getline(std::cin, amount);
  std::vector<std::string> keys = {"amount"};
  std::vector<std::string> values = {amount};
  std::vector<std::string> dataTypes = {"Number"};

  this->executeBash->executeBashScript("https://api.bitskins.com/wallet/deposit/zen/create", this->profile->user->getAPIKey(), keys, values, dataTypes);

  return true;
}

cpr::Response WalletDespoit::getCryptoAddress(std::string input)
{
  if(input.find("-h") != std::string::npos)
  {
    this->help->showHelp(false, input);
  }

  cpr::Response session = cpr::Post(cpr::Url{"https://api.bitskins.com/wallet/deposit/crypto/list_addresses"},
                                    cpr::Header{{"x-apikey",this->profile->user->getAPIKey()}},
                                    cpr::Body{});

  this->responseDisplayer->displayHttpResponse(this->em, session, session.text);

  return session;
}

bool WalletDespoit::getLitecoinAddress(std::string input)
{
  if(input.find("-h") != std::string::npos)
  {
    this->help->showHelp(false, input);
  }
  std::string uinput, type;
  std::cout << "please select the following type:\n1: legacy\n2: p2sh-segwit\n3: bech32\n";
  std::getline(std::cin, uinput);
  if(uinput == "1")
  {
    type = "legacy";
  }
  else if(uinput == "2")
  {
    type = "p2sh-segwit";
  }
  else 
  {
    type = "bech32";
  }
  std::vector<std::string> keys = {"type"};
  std::vector<std::string> values = {type};
  std::vector<std::string> dataTypes = {"string"};

  this->executeBash->executeBashScript("https://api.bitskins.com/wallet/deposit/crypto/get_litecoin_address", this->profile->user->getAPIKey(), keys, values, dataTypes);

  return true;
}

bool WalletDespoit::getEtheriumAddress(std::string input)
{
  if(input.find("-h") != std::string::npos)
  {
    this->help->showHelp(false, input);
  }

  std::string uinput, type;
  std::cout << "please select the following type:\n1: legacy\n2: p2sh-segwit\n3: bech32\n";
  std::getline(std::cin, uinput);
  if(uinput == "1")
  {
    type = "legacy";
  }
  else if(uinput == "2")
  {
    type = "p2sh-segwit";
  }
  else 
  {
    type = "bech32";
  }
  std::vector<std::string> keys = {"type"};
  std::vector<std::string> values = {type};
  std::vector<std::string> dataTypes = {"string"};
  this->executeBash->executeBashScript("https://api.bitskins.com/wallet/deposit/crypto/get_ethereum_address", this->profile->user->getAPIKey(), keys, values, dataTypes);

  return true;

}
bool WalletDespoit::getBitcoinAddress(std::string input)
{
  if(input.find("-h") != std::string::npos)
  {
    this->help->showHelp(false, input);
  }


  std::string uinput, type;
  std::cout << "please select the following type:\n1: legacy\n2: p2sh-segwit\n3: bech32\n";
  std::getline(std::cin, uinput);
  if(uinput == "1")
  {
    type = "legacy";
  }
  else if(uinput == "2")
  {
    type = "p2sh-segwit";
  }
  else 
  {
    type = "bech32";
  }
  std::vector<std::string> keys = {"type"};
  std::vector<std::string> values = {type};
  std::vector<std::string> dataTypes = {"string"};
  
  this->executeBash->executeBashScript("https://api.bitskins.com/wallet/deposit/crypto/get_bitcoin_address", this->profile->user->getAPIKey(), keys, values, dataTypes);

  return true;
}
