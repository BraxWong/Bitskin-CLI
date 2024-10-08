#include "../header/Help.h"
#include <iostream>
#include <stdio.h>
#include <iomanip>

bool HELP_H::Help::showHelp(bool fromHelpPage, std::string command) {
  if (fromHelpPage) {
    std::cout << "Help Page:\n";
    std::cout << "Currently this program has 41 commands available.\n";
    
    const int numCols = 3;
    const int colWidth = 35;

    std::cout << "-----------------------------------------------------------------------------------------------------------------" << std::endl;

    for (size_t i = 0; i < commands.size(); i += numCols) {
        for (size_t j = i; j < i + numCols && j < commands.size(); j++) {
            std::cout << std::left << std::setw(colWidth) << std::to_string(j + 1) + ": -" + commands[j] << " | ";
        }
        std::cout << std::endl;
    }

    std::cout << "-----------------------------------------------------------------------------------------------------------------" << std::endl;
    std::cout << "To obtain for information regarding one specific command, "
                 "type in the command you want with the argument -h\n";
    std::cout << "For example: -quit -h\n";
    std::cout << "Enter -q to leave the help page.\n";
  }
  while (true) {
    if (fromHelpPage) {
      std::getline(std::cin, command);
    }
    if (command == "-quit -h") {
      std::cout << "When -quit is entered, the program will be terminated.\n";
    } else if (command == "-help -h") {
      std::cout
          << "When -help is entered, a list of commands will be displayed. "
             "Users can add the extra argument -h along with their command to "
             "obtain the information regarding that command.\n";
    } else if (command == "-balance -h") {
      std::cout << "When -balance is entered, the user's balance on the "
                   "website Bitskins will be displayed.\n";
    } else if (command == "-session -h") {
      std::cout << "When -session is entered, a list of information regarding "
                   "the user's current Bitskins session will be displayed. "
                   "Information such as steam-id, email, country, steam "
                   "username and more will be shown.\n";
    } else if (command == "-tradelink -h") {
      std::cout << "When -tradelink is entered, the user will be required to "
                   "enter their updated steam trade link in order to update "
                   "this information on Bitskins. You can find your trade link "
                   "in http://steamcommunity.com/my/tradeoffers/privacy.\n";
    } else if (command == "-updateaccount -h") {
      std::cout
          << "When -updateaccount is entered, the user will be presented the "
             "option to update a selection of information on Bitskins. Such "
             "as: Currency, language, store_alias and more.\n";
    } else if (command == "-block -h") {
      std::cout << "When -block is entered, the user's Bitskins account will "
                   "be blocked. WARNING!!!You will have to go to Bitskins "
                   "website in order to unblock your account. Use this command "
                   "only if you really have to.\n";
    } else if (command == "-affiliate -h") {
      std::cout
          << "When -affiliate is entered, the user will be shown its "
             "affiliation information with Bitskins. If you have not activated "
             "the affiliation program, no information will be displayed.\n";
    } else if (command == "-claimmoney -h") {
      std::cout
          << "When -claimmoeny is entered, the user will be allowed to claim "
             "the balance that is obtained from Bitskins' affiliation program. "
             "Further information can be found on Bitskins' website. Notice, "
             "if you do not have an affilation program with Bitskins, you will "
             "get the error code: Not Activated. Which means you have not "
             "activated the Bitskins' affiliation program on your accout.\n";
    } else if (command == "-historicrewards -h") {
      std::cout << "When -historicrewards is entered, the user will be asked "
                   "to enter the limit and offset value. The information will "
                   "then be sent to the Bitskins' database.\n";
    } else if (command == "-setcode -h") {
      std::cout << "When -setcode is entered, the user will be asked to enter "
                   "their new affiliate code. If the user's current and new "
                   "affiliate code are the same, an error will be shown saying "
                   "a unique affiliate code is required. Else, the affiliate "
                   "code will be stored in Bitskins' database.\n";
    } else if (command == "-currencyrates -h") {
      std::cout << "When -currencyrates is entered, the user will get fiat and "
                   "crypto rates on the platform. Fiat rates are used for "
                   "provisional preview only. All in-platform transactions are "
                   "calculated in USD. Crypto currencies are used as based "
                   "rates for depositing and withdrawing.\n";
    } else if (command == "-feeplans -h") {
      std::cout << "When -feeplans is entered, the user will be presented with "
                   "Bitskins' available sale fee plans.\n";
    } else if (command == "-platformstatus -h") {
      std::cout << "When -platformstatus is entered, the user will be "
                   "presented with Bitskins' service status. Including "
                   "buy_order, instant_sell, and platform status.\n";
    } else if (command == "-sales -h") {
      std::cout << "When -sales is entered, the user will be presented with "
                   "the latest sales stats for an item.\n";
    } else if (command == "-pricingsummary -h") {
      std::cout
          << "When -pricingsummary is entered, the user will be presented with "
             "an item's sales stats, it can be filtered by date.\n";
    } else if (command == "-steaminventory -h") {
      std::cout << "When -steaminventory is entered, the user will be "
                   "presented with a list of items they have in their steam "
                   "inventory for that particular game.\n";
    } else if (command == "-steamtrades -h") {
      std::cout << "When -steamtrades is entered, the user will be presented a "
                   "list of steam trades for that particular game.\n";
    } else if (command == "-activetrades -h") {
      std::cout << "When -activetrades is entered, the user will be presented "
                   "a list of active steam trades for that particular game.\n";
    } else if (command == "-hashtrades -h") {
      std::cout << "When -hashtrades is entered, the user will be presented a "
                   "list of hashes of steam active trades.\n";
    } else if (command == "-walletstats -h") {
      std::cout << "When -walletstats is entered, users will be presented with "
                   "their Bitskins' wallet stats.\n";
    } else if (command == "-kyclimits -h") {
      std::cout << "When -kyclimits is entered, users will be presented with "
                   "their BItskins' KYC limits.\n";
    } else if (command == "-walletreports -h") {
      std::cout << "When -walletreports is entered, users will be presented "
                   "with their Bitskins' wallet reports.\n";
    } else if (command == "-generatewalletreports -h") {
      std::cout
          << "When -generatewalletreports is entered, users will be presented "
             "with their Bitskins' wallet reports of a certain date.\n";
    } else if (command == "-downloadwalletreports -h") {
      std::cout << "When -downloadwalletreports is entered, users will be able "
                   "to download their Bitskins's wallet reports.\n";
    } else if (command == "-depositbinance -h") {
      std::cout << "When -depositbianace is entered, users will be able to "
                   "enter the amount to be deposited to their Bitskins' "
                   "wallet. A url will be shown and users can enter that url "
                   "in their browsers to proceed with the payment.\n";
    } else if (command == "-depositZen -h") {
      std::cout << "When -depositZen is entered, users will be able to enter "
                   "the amount to be deposited to their Bitskins' wallet. A "
                   "url will be shown and users can enter that url in their "
                   "browsers to proceed with the payment.\n";
    } else if (command == "-getCryptoAddress -h") {
      std::cout << "When -getCryptoAddress is entered, users will be given a "
                   "list of cryptocurrency addresses.\n";
    } else if (command == "-getLitecoinAddress -h") {
      std::cout << "When -getLitecoinAddress is entered, users will be given a "
                   "list of litecoin addresses.\n";
    } else if (command == "-getEtheriumAddress -h") {
      std::cout << "When -getEtheriumAddress is entered, users will be given a "
                   "list of Etherium addresses.\n";
    } else if (command == "-getBitcoinAddress -h") {
      std::cout << "When -getBitcoinAddress is entered, users will be given a "
                   "list of Bitcoin addresses.\n";
    } else if (command == "-useGiftCode -h") {
      std::cout << "When -useGiftCode is entered, users will be asked to "
                   "insert the gift code. If the gift code is valid, users' "
                   "BItskins wallet fund will be updated.\n";
    } else if (command == "-getUsedGiftCodes -h") {
      std::cout << "When -getUsedGiftCodes is entered, users will be presented "
                   "with the number of gift codes they have used, and the list "
                   "of gift codes they have used.\n";
    } else if (command == "-getCards -h") {
      std::cout << "when -getCards is entered, users will be presented with a "
                   "list of credit cards that they have stored within their "
                   "Bitskins' account.\n";
    } else if (command == "-depositCard -h") {
      std::cout
          << "When -depositCard is entered, users will be able to deposit to "
             "their Bitskin account using their credit card.\n";
    } else if (command == "-withdrawlBitcoin -h") {
      std::cout << "When -withdrawlBitcoin is entered, users will be required "
                   "to enter their bitcoin address, two factor authenticator "
                   "code, and amount they would like to withdraw.\n";
    } else if (command == "-withdrawlLitecoin -h") {
      std::cout << "When -withdrawlLitecoin is entered, users will be required "
                   "to enter their litecoin address, two factor authenticator "
                   "code, and amount they would like to withdraw.\n";
    } else if (command == "-withdrawlEthereum -h") {
      std::cout << "When -withdrawlEthereum is entered, users will be required "
                   "to enter their ethereum address, two factor authenticator "
                   "code, and amount they would like to withdraw.\n";
    } else if (command == "-withdrawlBinance -h") {
      std::cout << "When -withdrawlBinance is entered, users will be required "
                   "to enter their Binance receiver, two factor authenticator "
                   "code, and amount they would like to withdraw.\n";
    } else if (command == "-withdrawlVisa -h") {
      std::cout
          << "When -withdrawlVisa is entered, users will be required to enter "
             "their visa credit card id, amount they would like to withdraw, "
             "credit card security code, and two factor authenticator code.\n";
    } else if (command == "-createAPIKey -h") {
      std::cout 
          << "When -createAPIKey is entered, it will first verify whether the user has "
             "entered their authentication token upon login. If not, it will ask for the "
             "authentication token again. Then it will provide the newly created API key "
             "if the authentication token is valid. If no response was given, that means "  
             "the authentication token the user provided is invalid.\n";
    } else if (command == "-disableAPIKey -h") {
      std::cout
          << "When -disableAPIKey is entered, it will disable the user's BitSkins API Key.\n";
    } else if (command == "-updateAPIKey -h"){
      std::cout 
          << "When -updateAPIKey is entered, it will ask the user for their new BitSkins API Key.\n";
    } else if (command == "-q") {
      break;
    } else {
      std::cout << "Command not found.\n";
    }
    if (!fromHelpPage) {
      break;
    }
  }
  return true;
}
