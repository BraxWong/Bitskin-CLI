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

cpr::Response Profile::getCurrentSession(UserCredentials* user)
{
  cpr::Response session = cpr::Get(cpr::Url{"https://api.bitskins.com/account/profile/me"}, 
                                   cpr::Authentication{user->getUsername(), user->getPassword(), cpr::AuthMode::DIGEST},
                                   cpr::Header{{"x-apikey", user->getAPIKey()}});
  std::cout << session.url << "\n" << session.status_code << "\n" << session.text << "\n";
  return session;
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
  return user;
}
