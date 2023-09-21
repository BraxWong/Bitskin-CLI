#include "../header/Profile.h"
#include <iostream>
#include <string>

cpr::Response Profile::getCurrentSession(std::string APIKEY, std::string username, std::string password) {
  cpr::Response session = cpr::Get(cpr::Url{"https://api.bitskins.com/account/profile/me"}, 
                                   cpr::Authentication{username, password, cpr::AuthMode::BASIC},
                                   cpr::Parameters{{"x-apikey", APIKEY}});
  std::cout << session.url << "\n" << session.status_code << "\n" << session.text << "\n";
  return session;
}
