#include "../header/UserCredentials.h"
#include <iostream>
#include <stdio.h>

void USERCREDENTIALS_H::UserCredentials::setAPIKey(std::string APIKey)
{
  this->APIKey = APIKey;
}

std::string UserCredentials::getAPIKey()
{
  return this->APIKey;
}
