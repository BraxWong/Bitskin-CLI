#include "../header/Listener.h"
#include "../header/Help.h"
#include <iostream>
#include <stdio.h>
#include <unistd.h>

void Listener::listenCommand()
{
  Help* help = new Help();
  std::string input;
  while (true)
  {
    std::cout << "Please enter a command to get started. If you need help with the program, please enter -help.\n";
    std::getline(std::cin, input);
    if(input == "-help")
    {
      help->showHelp(true); 
    }
    else if(input == "-quit")   
    {
      delete help;     
      break;
    }
    else if(input.find("-balance") != std::string::npos)
    {
      this->profile->getAccountBalance(input);
    }
    else if(input.find("-session") != std::string::npos)
    {
      this->profile->getCurrentSession(input);
    }
    else if(input.find("-tradelink") != std::string::npos)
    {
      this->profile->updateTradeLink(input);
    }
    else if(input.find("-updateaccount") != std::string::npos)
    {
      this->profile->updateAccount(input);
    }
    else if(input.find("-block") != std::string::npos)
    {
      this->profile->blockAccount(input);
    }
    else if(input.find("-affiliate") != std::string::npos)
    {
      this->affiliate->getAffiliateInfo(input);
    }
    else if(input.find("-claimmoney") != std::string::npos)
    {
      this->affiliate->claimMoney(input);
    }
    else if(input.find("-historicrewards") != std::string::npos)
    {
      this->affiliate->getListHistoricalRewards(input);
    }
    else if(input.find("-setcode") != std::string::npos)
    {
      this->affiliate->setAffiliateCode(input);
    }
    else if(input.find("-currencyrates") != std::string::npos)
    {
      this->currencyRates->getCurrencyRates(input);
    }
    else if(input.find("-feeplans") != std::string::npos)
    {
      this->feePlans->getFeePlans(input);
    }
    else if(input.find("-platformstatus") != std::string::npos)
    {
      this->platformStatus->getPlatformStatus(input);
    }
    else if(input.find("-sales") != std::string::npos)
    {
      this->pricing->getSales(input);
    }
    else if(input.find("-pricingsummary") != std::string::npos)
    {
      this->pricing->getPricingSummary(input);
    }
    else if(input.find("-userstore") != std::string::npos)
    {
      this->marketItems->userStores(input);
    }
    else if(input.find("-buysingle") != std::string::npos)
    {
      this->buyItem->buySingleItem(input);
    }
    else if(input.find("-steaminventory") != std::string::npos)
    {
      this->steamInventory->getSteamInventory(input);
    }
    else if(input.find("-steamtrades") != std::string::npos)
    {
      this->steamTrades->getSteamTrades(input);
    }
    else if(input.find("-activetrades") != std::string::npos)
    {
      this->steamTrades->getActiveSteamTrades(input);
    }
    else if(input.find("-hashtrades") != std::string::npos)
    {
      this->steamTrades->getSteamTradeHash(input);
    }
    else if(input.find("-walletstats") != std::string::npos)
    {
      this->walletStats->getWalletStats(input);
    }
    else if(input.find("-kyclimits") != std::string::npos)
    {
      this->walletStats->getKYCLimits(input);
    }
    else if(input.find("-walletreports") != std::string::npos)
    {
      this->walletReports->getWalletReports(input);
    }
    else if(input.find("-generatewalletreports") != std::string::npos)
    {
      this->walletReports->generateWalletReports(input);
    }
    else if(input.find("-downloadwalletreports") != std::string::npos)
    {
      this->walletReports->downloadWalletReports(input);
    }
    else if(input.find("-depositbinance") != std::string::npos)
    {
      this->walletDespoit->depositBinance(input);
    }
    else if(input.find("-depositZen") != std::string::npos)
    {
      this->walletDespoit->depositZen(input);
    }
    else if(input.find("-getCryptoAddress") != std::string::npos)
    {
      this->walletDespoit->getCryptoAddress(input);
    }
    else if(input.find("-getLitecoinAddress") != std::string::npos)
    {
      this->walletDespoit->getLitecoinAddress(input);
    }
    else if(input.find("-getEtheriumAddress") != std::string::npos)
    {
      this->walletDespoit->getEtheriumAddress(input);
    }
    else if(input.find("-getBitcoinAddress") != std::string::npos)
    {
      this->walletDespoit->getBitcoinAddress(input);
    }
    else if(input.find("-useGiftCode") != std::string::npos)
    {
      this->giftCode->useGiftCode(input);
    }
    else if(input.find("-getUsedGiftCodes") != std::string::npos)
    {
      this->giftCode->getUsedGiftCodes(input);
    }
    else if(input.find("-getCards") != std::string::npos)
    {
      this->card->getCards(input);
    }
    else if(input.find("-depositCard") != std::string::npos)
    {
      this->card->depositCard(input);
    }
    else if(input.find("-withdrawlBitcoin") != std::string::npos)
    {
      this->walletWithdrawl->withdrawlBitcoin(input);
    }
    else if(input.find("-withdrawlLitecoin") != std::string::npos)
    {
      this->walletWithdrawl->withdrawlLitecoin(input);
    }
    else if(input.find("-withdrawlEthereum") != std::string::npos)
    {
      this->walletWithdrawl->withdrawlEthereum(input);
    }
    else if(input.find("-withdrawlBinance") != std::string::npos)
    {
      this->walletWithdrawl->withdrawlBinance(input);
    }
    else if(input.find("-withdrawlVisa") != std::string::npos)
    {
      this->walletWithdrawl->withdrawlVisa(input);
    }
    else if(input.find("-createAPIKey") != std::string::npos)
    {
      this->apiKey->createAPIKey(input);
    }
    else if (input.find("-disableAPIKey") != std::string::npos)
    {
      this->apiKey->disableAPIKey(input);
    }
    else 
    {
      std::cout << "Command not recognized. Please try again.\n";
    }
  }
}
