#include "memplumber.h"
#include "src/CLI/header/Listener.h"
#include "src/CLI/header/MainMenu.h"


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
