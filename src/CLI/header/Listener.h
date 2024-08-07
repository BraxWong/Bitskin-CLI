#ifndef LISTENER_H
#define LISTENER_H
#include "../../Account/header/Profile.h"
#include "../../Account/header/Affiliate.h"
#include "../../Account/header/APIKey.h"
#include "../../Config/header/CurrencyRates.h"
#include "../../Config/header/FeePlans.h"
#include "../../Config/header/PlatformStatus.h"
#include "../../Market/header/Pricing.h"
#include "../../Market/header/MarketItems.h"
#include "../../Market/header/BuyItem.h"
#include "../../Steam/header/SteamInventory.h"
#include "../../Steam/header/SteamTrades.h"
#include "../../Wallet/header/WalletStats.h"
#include "../../Wallet/header/WalletReports.h"
#include "../../Wallet/header/WalletDeposit.h"
#include "../../Wallet/header/WalletWithdrawl.h"
#include "../../Wallet/header/GiftCode.h"
#include "../../Wallet/header/Card.h"
#include <cstdlib>
#include <stdlib.h>
#include <string>

class Listener
{
public:
  Profile* profile;
  Affiliate* affiliate;
  APIKey* apiKey;
  CurrencyRates* currencyRates;
  FeePlans* feePlans;
  PlatformStatus* platformStatus;
  Pricing* pricing;
  MarketItems* marketItems;
  BuyItem* buyItem;
  SteamInventory* steamInventory;
  SteamTrades* steamTrades;
  WalletStats* walletStats;
  WalletReports* walletReports;
  WalletDespoit* walletDespoit;
  GiftCode* giftCode;
  Card* card;
  WalletWithdrawl* walletWithdrawl;
/*╭━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╮
  ┃                                                                              ┃
  ┃   Function: Listener class constructor. Description: The constructor will    ┃
  ┃       store a copy of a Profile object to the current Listener object.       ┃
  ┃                                                                              ┃
  ╰━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╯
*/

    Listener(Profile* p, Affiliate* a, APIKey* apiKey, CurrencyRates* currencyRates, FeePlans* feePlans, PlatformStatus* platformStatus, Pricing* pricing, MarketItems* marketItems, BuyItem* buyItem, SteamInventory* steamInventory, SteamTrades* steamTrades, WalletStats* walletStats, WalletReports* walletReports, WalletDespoit* walletDespoit, GiftCode* giftCode, Card* card, WalletWithdrawl* walletWithdrawl)
  {
    this->profile = p;
    this->affiliate = a;
    this->apiKey = apiKey;
    this->currencyRates = currencyRates;
    this->feePlans = feePlans;
    this->platformStatus = platformStatus;
    this->pricing = pricing;
    this->marketItems = marketItems;
    this->buyItem = buyItem;
    this->steamInventory = steamInventory;
    this->steamTrades = steamTrades;
    this->walletStats = walletStats;
    this->walletReports = walletReports;
    this->walletDespoit = walletDespoit;
    this->giftCode = giftCode;
    this->card = card;
    this->walletWithdrawl = walletWithdrawl;
  }

    ~Listener()
    {
      delete this->affiliate;
      delete this->apiKey;
      delete this->marketItems;
      delete this->pricing;
      delete this->platformStatus;
      delete this->feePlans;
      delete this->currencyRates;
      delete this->steamTrades;
      delete this->walletStats;
      delete this->walletReports;
      delete this->walletDespoit;
      delete this->giftCode;
      delete this->card;
      delete this->walletWithdrawl;
    }

/*╭━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╮
  ┃                                                                              ┃
  ┃     Function: listenCommand() Description: This method will perpeutally      ┃
  ┃      listen to user's command until a -help command is received. Please      ┃
  ┃                 refer to Listener.cxx for more information.                  ┃
  ┃                                                                              ┃
  ╰━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╯
*/

  void listenCommand();

private:
};
#endif // !LISTENER_H
