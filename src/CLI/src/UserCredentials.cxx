#include "../header/UserCredentials.h"
#include <iostream>
#include <stdio.h>
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
