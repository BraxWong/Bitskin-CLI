#include "../src/CLI/header/UserCredentials.h"
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/catch_test_macros.hpp>
#include <iostream>
#include <stdio.h>

bool testAPIKeyValidity(UserCredentials *uc, std::string APIKey) {
  if (uc->getAPIKey() == APIKey) {
    return true;
  }
  return false;
}

bool testAuthTokenValidity(UserCredentials *uc, std::string AuthToken) {
  if (uc->getAuthToken() == AuthToken)
    return true;
  return false;
}

TEST_CASE("testAuthTokenValidity()", "[testAuthTokenValidity") {
  std::cout << "Running testAuthTokenValidity() test.\n";
  UserCredentials *uc = new UserCredentials();
  uc->setAuthToken("12345678");
  REQUIRE(testAuthTokenValidity(uc, "12345678") == true);
  REQUIRE(testAuthTokenValidity(uc, "12345677jsafjhdsjfds") == false);
}

TEST_CASE("testAPIKeyValidity()", "[testAPIKeyValidity]") {
  std::cout << "Running testAPIKeyValidity() test.\n";
  UserCredentials *uc = new UserCredentials();
  uc->setAPIKey("APIKey");
  REQUIRE(testAPIKeyValidity(uc, "APIKey") == true);
  REQUIRE(testAPIKeyValidity(uc, "APIKEY") == false);
  delete uc;
}
