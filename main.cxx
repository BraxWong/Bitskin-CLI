#include "src/Account/header/Affiliate.h"
#include "src/Config/header/CurrencyRates.h"
#include "src/Config/header/FeePlans.h"
#include "src/Config/header/PlatformStatus.h"
#include "src/Market/header/Pricing.h"
#include "src/Market/header/MarketItems.h"
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



/*       ╭━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╮
         ┃                                                              ┃
         ┃ TODO: Create a class that includes all the rest-api classes. ┃
         ┃                                                              ┃
         ╰━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╯
*/

int main() {
  MemPlumber::start();
  CLI *cli = new CLI();
  cli->showCLIGreetings();
  Profile* profile = new Profile();
  profile->userLogin();
  Affiliate* affiliate = new Affiliate(profile);
  CurrencyRates* currencyRates = new CurrencyRates(profile);
  FeePlans* feePlans = new FeePlans(profile);
  PlatformStatus* platformStatus = new PlatformStatus(profile);
  Pricing* pricing = new Pricing(profile);
  MarketItems* marketItems = new MarketItems(profile);
  Listener* listener = new Listener(profile, affiliate, currencyRates, feePlans, platformStatus, pricing, marketItems);
  listener->listenCommand();
  MemPlumber::stopAndFreeAllMemory();
  return 0;
}
