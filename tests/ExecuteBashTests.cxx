#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include "../src/bash/header/ExecuteBash.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>

using json = nlohmann::json;

bool testCreateBashCMD(std::vector<std::string> expected, std::string url, std::string APIKey, std::vector<std::string> keys, std::vector<std::string> values, std::vector<std::string> dataType)
{
  ExecuteBash executeBash;
  std::vector<std::string> data = executeBash.createBashCMD(url, APIKey, keys, values, dataType);
  if(expected == data)
  {
    return true;
  }
  return false;
}

TEST_CASE("testCreateBashCMD()","[testCreateBashCMD]")
{
  std::cout << "Running createBashCMD() test.\n";
  REQUIRE(testCreateBashCMD({"curl -s url", "-X POST", "-H 'content-type: application/json'", "-H 'x-apikey: apikey'", "--dataRaw '{}'"}, "url", "apikey", {}, {}, {})== true);
}
