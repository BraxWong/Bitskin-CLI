#include <string>
enum APPID
{
  cs2 = 730,
  dota2 = 570,
  tf2 = 440,
  rust = 252490
};

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

std::string getAppIDString(APPID appID);
std::string getInventoryStatusString(INVENTORYSTATUS inventoryStatus);

