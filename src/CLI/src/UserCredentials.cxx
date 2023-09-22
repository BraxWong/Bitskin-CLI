#include "../header/UserCredentials.h"
#include <iostream>
#include <stdio.h>

void UserCredentials::setUsername(std::string username)
{
  this->Username = username;
}

void UserCredentials::setPassword(std::string password)
{
  this->Password = password;
}

void UserCredentials::setAPIKey(std::string APIKey)
{
  this->APIKey = APIKey;
}

std::string UserCredentials::getUsername()
{
  return this->Username;
}

std::string UserCredentials::getPassword()
{
  return this->Password;
}

std::string UserCredentials::getAPIKey()
{
  return this->APIKey;
}
