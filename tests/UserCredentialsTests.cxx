#include "../src/CLI/header/UserCredentials.h"
#include <iostream>
#include <stdio.h>
#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>

bool testUsernameValidity(UserCredentials* uc, std::string username)
{
  if(uc->getUsername() == username) 
  {
    return true;
  }
  return false;
}

bool testPasswordValidity(UserCredentials* uc, std::string password)
{
  if(uc->getPassword() == password)
  {
    return true;
  }
  return false;
}

bool testAPIKeyValidity(UserCredentials* uc, std::string APIKey)
{
  if(uc->getAPIKey() == APIKey)
  {
    return true;
  }
  return false;
}

TEST_CASE("testUsernameValidity()","[testUsernameValidity]")
{
  std::cout << "Running testUsernameValidity() test.\n";
  UserCredentials* uc = new UserCredentials();
  uc->setUsername("username");
  REQUIRE(testUsernameValidity(uc,"username") == true);
  REQUIRE(testUsernameValidity(uc,"password") == false);
  delete uc;
}

TEST_CASE("testPasswordValidity()","[testPasswordValidity]")
{
  std::cout << "Running testPasswordValidity() test.\n";
  UserCredentials* uc = new UserCredentials();
  uc->setPassword("password");
  REQUIRE(testPasswordValidity(uc,"password") == true);
  REQUIRE(testPasswordValidity(uc,"username") == false);
  delete uc;
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
