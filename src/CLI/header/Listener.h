#ifndef LISTENER_H
#define LISTENER_H
#include "../../Account/header/Profile.h"
#include "../../Account/header/Affiliate.h"
#include "../../Config/header/CurrencyRates.h"
#include "../../Config/header/FeePlans.h"
#include "../../Config/header/PlatformStatus.h"
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

/*╭━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╮
  ┃                                                                              ┃
  ┃   Function: Listener class constructor. Description: The constructor will    ┃
  ┃       store a copy of a Profile object to the current Listener object.       ┃
  ┃                                                                              ┃
  ╰━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╯
*/

  Listener(Profile* p, Affiliate* a, CurrencyRates* currencyRates, FeePlans* feePlans, PlatformStatus* platformStatus)
  {
    this->profile = p;
    this->affiliate = a;
    this->currencyRates = currencyRates;
    this->feePlans = feePlans;
    this->platformStatus = platformStatus;
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
