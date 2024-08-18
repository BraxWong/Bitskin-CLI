#ifndef HELP_H
#define HELP_H
#include <stdlib.h>
#include <cstdlib>
#include <stdio.h>
#include <string>
#include <vector>
class Help
{
  public:
    std::vector<std::string> commands = {
        "help", "quit", "balance", "session", "tradelink",
        "updateaccount", "block", "affiliate", "claimmoney",
        "historicrewards", "setcode", "currencyrates",
        "platformstatus", "sales", "pricingsummary", "steaminventory",
        "steamtrades", "activetrades", "walletstats", "kyclimits",
        "walletreports", "generatewalletreports", "downloadwalletreports",
        "depositbianace", "getCryptoAddress", "getLitecoinAddress",
        "getEtheriumAddress", "getBitcoinAddress", "useGiftCode",
        "getUsedGiftCodes", "depositZen", "getCards", "depositCard",
        "withdrawlBitcoin", "withdrawlLitecoin", "withdrawlEthereum",
        "withdrawlBinance", "withdrawlVisa", "createAPIKey",
        "disableAPIKey", "updateAPIKey"
    };
    bool showHelp(bool fromHelpPage, std::string command = "NONE");
};
#endif // !HELP_H
