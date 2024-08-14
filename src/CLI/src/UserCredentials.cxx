#include "../header/UserCredentials.h"
#include <iostream>
#include <stdio.h>
#include <fstream>

bool USERCREDENTIALS_H::UserCredentials::setAPIKey(std::string APIKey)
{
  bool apiSet = false;
  if(checkAPIKeyValidity(APIKey) == true)
  {
    this->APIKey = APIKey;
    apiSet = true;
  } 
  return apiSet;
}

bool USERCREDENTIALS_H::UserCredentials::checkAPIKeyValidity(std::string APIKey)
{
  return APIKey.length() == VALID_API_KEY_LENGTH;
}

void USERCREDENTIALS_H::UserCredentials::setAuthToken(std::string AuthToken) {
  this->authToken = AuthToken;
}
std::string UserCredentials::getAPIKey() { return this->APIKey; }

std::string UserCredentials::getAuthToken() { return this->authToken; }

bool UserCredentials::writeAPIKeyToFile(std::string APIKey) {
  bool wroteToFile = true;
  if(!this->checkAPIKeyValidity(APIKey)){
    wroteToFile = false;
    std::cout << "The key is invalid?\n";
  }
  else {
    std::ofstream APIKeyFile("../Resources/APIKey.txt");
    APIKeyFile << APIKey;
    APIKeyFile.close();
  }
  return wroteToFile;
}

std::string UserCredentials::readAPIKeyFromFile() {
  std::string apiKey = "";
  std::ifstream apiKeyFile("../Resources/APIKey.txt");
  std::getline(apiKeyFile, apiKey);
  if(apiKey.length() != VALID_API_KEY_LENGTH){
    apiKey = "";
  }
  return apiKey;
}
