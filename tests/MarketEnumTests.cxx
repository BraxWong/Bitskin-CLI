#include "../src/Market/header/MarketEnum.h"
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/catch_test_macros.hpp>
#include <iostream>
#include <stdio.h>

std::string testGetAppIDString(APPID appID)
{
  return getAppIDString(appID);
}

std::string testGetInventoryStatusString(INVENTORYSTATUS inventoryStatus)
{
  return getInventoryStatusString(inventoryStatus);
}

TEST_CASE("testGetAppIDString", "[testGetAppIDString]")
{
  REQUIRE(testGetAppIDString(APPID::cs2) == "cs2");
  REQUIRE(testGetAppIDString(APPID::dota2) == "dota2");
  REQUIRE(testGetAppIDString(APPID::tf2) == "tf2");
  REQUIRE(testGetAppIDString(APPID::rust) == "rust");
}

TEST_CASE("testGetInventoryStatusString", "[testGetInventoryStatusString]")
{
  REQUIRE(testGetInventoryStatusString(INVENTORYSTATUS::issue) == "issue");
  REQUIRE(testGetInventoryStatusString(INVENTORYSTATUS::not_available) == "not_available");
  REQUIRE(testGetInventoryStatusString(INVENTORYSTATUS::deleted) == "deleted");
  REQUIRE(testGetInventoryStatusString(INVENTORYSTATUS::withdrawn) == "withdrawn");
  REQUIRE(testGetInventoryStatusString(INVENTORYSTATUS::delisted) == "delisted");
  REQUIRE(testGetInventoryStatusString(INVENTORYSTATUS::ready) == "ready");
  REQUIRE(testGetInventoryStatusString(INVENTORYSTATUS::listed) == "listed");
  REQUIRE(testGetInventoryStatusString(INVENTORYSTATUS::listed_private) == "listed_private");
  REQUIRE(testGetInventoryStatusString(INVENTORYSTATUS::sold) == "sold");
  REQUIRE(testGetInventoryStatusString(INVENTORYSTATUS::withdraw_queue) == "withdraw_queue");
  REQUIRE(testGetInventoryStatusString(INVENTORYSTATUS::withdraw_pending) == "withdraw_pending");
  REQUIRE(testGetInventoryStatusString(INVENTORYSTATUS::instant_sell) == "instant_sell");
}
