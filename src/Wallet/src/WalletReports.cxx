#include "../header/WalletReports.h"
#include <iostream>
#include <string>

bool WalletReports::getWalletReports(std::string input)
{
  if(input.find("-h") != std::string::npos)
  {
    this->help->showHelp(false, input);
  }
  std::string type, status;
  std::cout << "Please enter the type: \n";
  std::getline(std::cin, type);
  std::cout << "Please enter the status: \n";
  std::getline(std::cin, status);
  std::vector<std::string> keys = {"type","status"};
  std::vector<std::string> values = {type, status};
  std::vector<std::string> dataTypes = {"Number", "Number"};

  this->executeBash->executeBashScript("https://api.bitskins.com/wallet/report/list", this->profile->user->getAPIKey(), keys, values, dataTypes);

  return true;

}


bool WalletReports::generateWalletReports(std::string input)
{
  if(input.find("-h") != std::string::npos)
  {
    this->help->showHelp(false, input);
  }
  std::string reportType, date;
  std::cout << "Balance: Press 1\nSell: Press 2\nBuy: Press3\n";
  std::getline(std::cin, reportType);
  std::cout << "Please enter the date of the wallet status you want to review.(YYYY-MM)\n";
  std::getline(std::cin, date);
  std::vector<std::string> keys = {"type","date"};
  std::vector<std::string> values = {reportType, date};
  std::vector<std::string> dateTypes = {"String","String"};

  this->executeBash->executeBashScript("https://api.bitskins.com/wallet/report/generate", this->profile->user->getAPIKey(), keys, values, dataTypes);
  
  return true;
}


bool WalletReports::downloadWalletReports(std::string input)
{
  if(input.find("-h") != std::string::npos)
  {
    this->help->showHelp(false, input);
  }

  std::string id;
  std::cout << "Please provide your ID.\n";
  std::getline(std::cin, id);
  std::vector<std::string> keys = {"id"};
  std::vector<std::string> values = {id};
  std::vector<std::string> dataTypes = {"String"};

  this->executeBash->executeBashScript("https://api.bitskins.com/wallet/report/download", this->profile->user->getAPIKey(), keys, values, dataTypes);
  
  return true;
}

