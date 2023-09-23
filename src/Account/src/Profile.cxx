#include "../header/Profile.h"
#include <iostream>
#include <string>

/*╭━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╮
  ┃                                                                              ┃
  ┃     TODO: Maybe create a separate class for showing the error message if     ┃
  ┃              the request was not able to fulfill successfully.               ┃
  ┃                                                                              ┃
  ╰━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╯
*/

cpr::Response Profile::getCurrentSession()
{
  cpr::Response session = cpr::Get(cpr::Url{"https://api.bitskins.com/account/profile/me"}, 
                                   cpr::Authentication{this->user->getUsername(), this->user->getPassword(), cpr::AuthMode::DIGEST},
                                   cpr::Header{{"x-apikey",this->user->getAPIKey()}});
  std::cout << session.url << "\n" << session.status_code << "\n" << session.text << "\n";
  return session;
}

cpr::Response Profile::getAccountBalance()
{
  cpr::Response balance = cpr::Post(cpr::Url{"https://api.bitskins.com/account/profile/balance"},
                                    cpr::Authentication{this->user->getUsername(), this->user->getPassword(), cpr::AuthMode::DIGEST},
                                    cpr::Header{{"x-apikey",this->user->getAPIKey()}},
                                    cpr::Body{});
  std::cout << balance.url << "\n" << balance.status_code << "\n" << balance.text << "\n";
  return balance;
}

/*                ╭━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╮
                  ┃                                            ┃
                  ┃ TODO: Validate the input given by the user ┃
                  ┃                                            ┃
                  ╰━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╯
*/

UserCredentials* Profile::userLogin()
{
  UserCredentials* user = new UserCredentials();
  std::cout << "Please insert your steam username:\n";
  std::string input;
  std::cin >> input;
  user->setUsername(input);
  std::cout << "Please insert your steam password:\n";
  std::cin >> input;
  user->setPassword(input);
  std::cout << "Please insert your Bitskins API key:\n";
  std::cin >> input;
  user->setAPIKey(input);
  this->user = user;
  return user;
}
