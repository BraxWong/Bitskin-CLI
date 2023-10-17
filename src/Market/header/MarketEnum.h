#include <string>


/*              ╭━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╮
                ┃                                                 ┃
                ┃ ENUM: APPID Description: AppID for applications ┃
                ┃                                                 ┃
                ╰━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╯
*/

enum APPID
{
  cs2 = 730,
  dota2 = 570,
  tf2 = 440,
  rust = 252490
};


/*╭━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╮
  ┃                                                                              ┃
  ┃      ENUM: INVENTORYSTATUS Description: Provides insight to the user's       ┃
  ┃                          bitskins inventory status                           ┃
  ┃                                                                              ┃
  ╰━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╯
*/

enum INVENTORYSTATUS
{
  issue = -4,
  not_available = -3,
  deleted = -2,
  withdrawn = -1,
  delisted = 0,
  ready = 1,
  listed = 2,
  listed_private = 3,
  sold = 4,
  withdraw_queue = 5,
  withdraw_pending = 6,
  instant_sell = 7
};

/*╭━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╮
  ┃                                                                              ┃
  ┃    Function: getAppIDString() Description: Will return the                   ┃
  ┃                      string according to the ENUM value                      ┃
  ┃                                                                              ┃
  ╰━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╯
*/


std::string getAppIDString(APPID appID);

/*╭━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╮
  ┃                                                                              ┃
  ┃    Function: getInventoryStatusString() Description: Will return the         ┃
  ┃                      string according to the ENUM value                      ┃
  ┃                                                                              ┃
  ╰━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╯
*/


std::string getInventoryStatusString(INVENTORYSTATUS inventoryStatus);

