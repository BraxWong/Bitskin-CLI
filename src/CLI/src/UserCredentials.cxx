#include "../header/UserCredentials.h"
#include <iostream>
#include <stdio.h>

void USERCREDENTIALS_H::UserCredentials::setUsername(std::string username)
{
  this->Username = username;
}

void USERCREDENTIALS_H::UserCredentials::setPassword(std::string password)
{
  this->Password = password;
}

void USERCREDENTIALS_H::UserCredentials::setAPIKey(std::string APIKey)
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
