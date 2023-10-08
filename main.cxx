#include "src/Account/header/Affiliate.h"
#include "src/CLI/header/MainMenu.h"
#include "src/Account/header/Profile.h"
#include "src/CLI/header/Listener.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <nlohmann/json.hpp>
#include <string>
#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include "memplumber.h"


int main() {
  MemPlumber::start();
  CLI *cli = new CLI();
  cli->showCLIGreetings();
  Profile* profile = new Profile();
  profile->userLogin();
  Affiliate* affiliate = new Affiliate(profile);
  Listener* listener = new Listener(profile, affiliate);
  listener->listenCommand();
  MemPlumber::stopAndFreeAllMemory();
  return 0;
}
