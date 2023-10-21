#ifndef LISTENER_H
#define LISTENER_H
#include "../../Account/header/Profile.h"
#include "../../Account/header/Affiliate.h"
#include "../../Config/header/CurrencyRates.h"
#include "../../Config/header/FeePlans.h"
#include "../../Config/header/PlatformStatus.h"
#include "../../Market/header/Pricing.h"
#include "../../Market/header/MarketItems.h"
#include "../../Market/header/BuyItem.h"
#include "CMDVector.h"
#include <cstdlib>
#include <stdlib.h>
#include <string>

class Listener
{
public:
  Profile* profile;
  Affiliate* affiliate;
  CurrencyRates* currencyRates;
  FeePlans* feePlans;
  PlatformStatus* platformStatus;
  Pricing* pricing;
  MarketItems* marketItems;
  BuyItem* buyItem;
  CMDStack* cmdStack = new CMDStack();
/*╭━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╮
  ┃                                                                              ┃
  ┃   Function: Listener class constructor. Description: The constructor will    ┃
  ┃       store a copy of a Profile object to the current Listener object.       ┃
  ┃                                                                              ┃
  ╰━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╯
*/

    Listener(Profile* p, Affiliate* a, CurrencyRates* currencyRates, FeePlans* feePlans, PlatformStatus* platformStatus, Pricing* pricing, MarketItems* marketItems, BuyItem* buyItem)
  {
    this->profile = p;
    this->affiliate = a;
    this->currencyRates = currencyRates;
    this->feePlans = feePlans;
    this->platformStatus = platformStatus;
    this->pricing = pricing;
    this->marketItems = marketItems;
    this->buyItem = buyItem;
  }

    ~Listener()
    {
      delete this->affiliate;
      delete this->cmdStack;
      delete this->marketItems;
      delete this->pricing;
      delete this->platformStatus;
      delete this->feePlans;
      delete this->currencyRates;
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
