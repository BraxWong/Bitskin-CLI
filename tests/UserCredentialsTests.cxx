#include "../src/CLI/header/UserCredentials.h"
#include <iostream>
#include <stdio.h>
#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>

bool testAPIKeyValidity(UserCredentials* uc, std::string APIKey)
{
  if(uc->getAPIKey() == APIKey)
  {
    return true;
  }
  return false;
}

TEST_CASE("testAPIKeyValidity()","[testAPIKeyValidity]")
{
  std::cout << "Running testAPIKeyValidity() test.\n";
  UserCredentials* uc = new UserCredentials();
  uc->setAPIKey("APIKey");
  REQUIRE(testAPIKeyValidity(uc,"APIKey") == true);
  REQUIRE(testAPIKeyValidity(uc,"APIKEY") == false);
  delete uc;
}
