#include "../header/MarketEnum.h"
#include <stdio.h>
#include <iostream>

std::string getAppIDString(APPID appID)
{
  switch(appID)
  {
    case cs2 : return "cs2";
    case dota2 : return "dota2";
    case tf2 : return "tf2";
    case rust : return "rust";
    default: return "Error";
  }
}

std::string getInventoryStatusString(INVENTORYSTATUS inventoryStatus)
{
  switch(inventoryStatus)
  {
    case issue : return "issue";
    case not_available : return "not_available";
    case deleted : return "deleted";
    case withdrawn : return "withdrawn";
    case delisted : return "delisted";
    case ready : return "ready";
    case listed : return "listed";
    case listed_private : return "listed_private";
    case sold : return "sold";
    case withdraw_queue : return "withdraw_queue";
    case withdraw_pending : return "withdraw_pending";
    case instant_sell : return "instant_sell";
    default : return "Error";
  }
}
