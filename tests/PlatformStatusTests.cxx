#include "../src/Config/header/PlatformStatus.h"
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/catch_test_macros.hpp>
#include <iostream>
#include <stdio.h>

std::string testGlobalPlatformStatus(Global_Platform_Status status) {
  return getGlobalPlatformStatusString(status);
}

TEST_CASE("testGlobalPlatformStatus()", "[testGlobalPlatformStatus]") {
  std::cout << "Running testGlobalPlatformStatus() test.\n";
  REQUIRE(testGlobalPlatformStatus(Global_Platform_Status::loading) == "loading");
  REQUIRE(testGlobalPlatformStatus(Global_Platform_Status::offline) == "offline");
  REQUIRE(testGlobalPlatformStatus(Global_Platform_Status::steam_down) == "steam_down");
  REQUIRE(testGlobalPlatformStatus(Global_Platform_Status::active) == "active");
}
