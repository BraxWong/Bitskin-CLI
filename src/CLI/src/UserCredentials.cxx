#include "../header/UserCredentials.h"
#include <iostream>
#include <stdio.h>

void USERCREDENTIALS_H::UserCredentials::setAPIKey() {
  std::string APIKey;
  while (true) {
    std::cout << "Please insert your Bitskins Auth Token:\n";
    std::getline(std::cin, APIKey);
    if (APIKey.length() == 64) {
      this->APIKey = APIKey;
      return;
    }
    std::cout << "The API Key has to be 64 characters long. Please try "
                 "again.\n";
  }
}

void USERCREDENTIALS_H::UserCredentials::setAuthToken(std::string AuthToken) {
  this->authToken = AuthToken;
}
std::string UserCredentials::getAPIKey() { return this->APIKey; }

std::string UserCredentials::getAuthToken() { return this->authToken; }
