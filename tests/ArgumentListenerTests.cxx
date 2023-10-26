#include "../src/CLI/header/ResponseDisplayer.h"
#include <iostream>
#include <stdio.h>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

bool testDisplayArgumentInfoOnly(ResponseDisplayer* listener, json j, std::string input)
{
  return listener->displayArgumentInfoOnly(j, input);
}


TEST_CASE("testDisplayArgumentInfoOnly()","[testDisplayArgumentInfoOnly]")
{
  std::cout << "Running testDisplayArgumentInfoOnly() tests.\n";
  ResponseDisplayer* listener = new ResponseDisplayer();
  json ex1 = json::parse(R"(
  {
    "steam_id": 12345,
    "wbalance": 1000
  }
  )");
  REQUIRE(testDisplayArgumentInfoOnly(listener, ex1, "-session -arg steam_id") == true);
  REQUIRE(testDisplayArgumentInfoOnly(listener, ex1, "-session") == false);
  REQUIRE(testDisplayArgumentInfoOnly(listener, ex1, "-session -arg steam_username") == false);
  delete listener;
}
