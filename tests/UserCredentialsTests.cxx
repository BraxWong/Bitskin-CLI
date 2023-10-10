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

TEST_CASE("testUsernameValidity()","[testUsernameValidity]")
{
  std::cout << "Running testUsernameValidity() test.\n";
  UserCredentials* uc = new UserCredentials();
  uc->setUsername("username");
  REQUIRE(testUsernameValidity(uc,"username") == true);
}
