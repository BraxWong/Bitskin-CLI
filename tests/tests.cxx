#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include "../src/CLI/header/UserCredentials.h"
bool returnTrue()
{
  return true;
}

bool test2()
{
  UserCredentials* uc = new UserCredentials();
  if(uc != nullptr)
  {
    return true;
  }
  return false;
}
TEST_CASE("returnTrue()","[returnTrue]")
{
  REQUIRE(returnTrue() == true);
  REQUIRE(test2() == true);
}


