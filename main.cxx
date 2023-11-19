#include "src/CLI/header/Listener.h"
#include "src/CLI/header/MainMenu.h"
#include "src/Wallet/header/WalletDeposit.h"


/*       ╭━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╮
         ┃                                                              ┃
         ┃ TODO: Create a class that includes all the rest-api classes. ┃
         ┃                                                              ┃
         ╰━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╯
*/

int main() {
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
  BuyItem* buyItem = new BuyItem(profile);
  SteamInventory* steamInventory = new SteamInventory(profile);
  SteamTrades* steamTrades = new SteamTrades(profile);
  WalletStats* walletStats = new WalletStats(profile);
  WalletReports* walletReports = new WalletReports(profile);
  WalletDespoit* walletDeposit = new WalletDespoit(profile);
  GiftCode* giftCode = new GiftCode(profile);
  Listener* listener = new Listener(profile, affiliate, currencyRates, feePlans, platformStatus, pricing, marketItems, buyItem, steamInventory, steamTrades, walletStats, walletReports, walletDeposit, giftCode);
  listener->listenCommand();
  delete cli;
  delete profile;
  delete listener;
  delete buyItem;
  delete steamInventory;
  return 0;
}
