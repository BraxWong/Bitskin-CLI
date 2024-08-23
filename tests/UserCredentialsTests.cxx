#include "../src/CLI/header/UserCredentials.h"
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/catch_test_macros.hpp>
#include <iostream>
#include <stdio.h>
bool testAPIKeyValidity(UserCredentials* uc, std::string APIKey)
{
  return uc->getAPIKey() == APIKey;
}

bool testAPIKeyLengthValidity(UserCredentials* uc, std::string APIKey)
{
  return uc->setAPIKey(APIKey);
}

bool testAuthTokenValidity(UserCredentials *uc, std::string AuthToken) {
  if (uc->getAuthToken() == AuthToken)
    return true;
  return false;
}

bool testWriteAPIKeyToFile(UserCredentials *uc, std::string APIKey) {
  bool testPassed = true;
  if(uc->writeAPIKeyToFile(APIKey) == false) {
    testPassed = false; 
  }
  else {
    std::string fileAPIKey;
    fileAPIKey = uc->readAPIKeyFromFile();
    if(APIKey != fileAPIKey) {
      testPassed = false;
    }
  }
  return testPassed;
}

TEST_CASE("testAuthTokenValidity()", "[testAuthTokenValidity]") {
  std::cout << "Running testAuthTokenValidity() test.\n";
  UserCredentials *uc = new UserCredentials();
  uc->setAuthToken("12345678");
  REQUIRE(testAuthTokenValidity(uc, "12345678") == true);
  REQUIRE(testAuthTokenValidity(uc, "12345677jsafjhdsjfds") == false);
}

TEST_CASE("testAPIKeyValidity()", "[testAPIKeyValidity]") {
  std::cout << "Running testAPIKeyValidity() test.\n";
  UserCredentials* uc = new UserCredentials();
  uc->setAPIKey("THISISANAPIKEYTHATISATLEASTSIXTY-FOURCHARACTERSLONGIPROMISEIAMNO");
  REQUIRE(testAPIKeyValidity(uc,"THISISANAPIKEYTHATISATLEASTSIXTY-FOURCHARACTERSLONGIPROMISEIAMNO") == true);
  REQUIRE(testAPIKeyValidity(uc,"APIKEY") == false);
  delete uc;
}

TEST_CASE("testAPIKeyLengthValidity()", "[testAPIKeyLengthValidity]")
{
  std::cout << "Running testAPIKeyLengthValidity() test.\n";
  UserCredentials* uc = new UserCredentials();
  REQUIRE(testAPIKeyLengthValidity(uc, "1234582347189372189073291873289173289173089217308912730812703811") == true);
  REQUIRE(testAPIKeyLengthValidity(uc, "123458234718937218907329187328917328917308921730891273081270381") == false);
  delete uc;
}

TEST_CASE("testWriteAPIKeyToFile()", "[testWriteAPIKeyToFile]")
{
  std::cout << "Running testWriteAPIKeyToFile() test.\n";
  UserCredentials* uc = new UserCredentials();
  REQUIRE(testWriteAPIKeyToFile(uc, "328907589013728904378910-42132143612648675786457546546455214214") == false);
  REQUIRE(testWriteAPIKeyToFile(uc, "328907589013728904378910-421321436126486757864575465464552142141") == true);
}
