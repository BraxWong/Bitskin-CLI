#include "../src/Account/header/Profile.h"
#include "../src/CLI/header/Error.h"
#include "../src/CLI/header/UserCredentials.h"
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/catch_test_macros.hpp>
#include <iostream>
#include <stdio.h>
#include <string>
using json = nlohmann::json;

bool checkErrorMap(std::string username, std::string password,
                   std::string APIKey) {
  Profile *profile = new Profile();
  UserCredentials *uc = new UserCredentials();
  profile->em = new ERRORMAP::errormap();
  uc->setAPIKey(APIKey);
  profile->user = uc;
  cpr::Response response = profile->getCurrentSession("-session");
  json j = json::parse(response.text);
  for (auto const &x : profile->em->errorMap) {
    if (j["code"] == x.first) {
      return true;
    }
  }
  return false;
}

bool checkErrorResponse(json j) {
  ERRORMAP::errormap *errorMap = new ERRORMAP::errormap();
  return errorMap->checkErrorResponse(j);
}

/* ╭━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╮
   ┃                                                                          ┃
   ┃ TODO: Might be a good idea to create a dummy steam and bitskins account. ┃
   ┃                                                                          ┃
   ╰━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╯
*/

TEST_CASE("checkErrorMap()", "[checkErrorMap]") {
  std::cout << "Running checkErrorMap() test.\n";
  REQUIRE(checkErrorMap("blah", "blah", "blah") == true);
}