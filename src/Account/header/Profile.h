#ifndef PROFILE_H
#define PROFILE_H
#include <cpr/cpr.h>
#include "../../CLI/header/UserCredentials.h"
#include "../../CLI//header/Help.h"
#include "../../CLI/header/Error.h"
#include "../../bash/header/ExecuteBash.h"
#include "../../CLI/header/ResponseDisplayer.h"
#include <cstdlib>
#include <stdlib.h>
#include <string>
#include <nlohmann/json.hpp>
#include <vector>

class Profile {
public:
  UserCredentials* user;
  Help* help;
  ERRORMAP::errormap* em;
  ResponseDisplayer* responseDisplayer;
  ExecuteBash* executeBash;
  Profile()
  {
    this->responseDisplayer = new ResponseDisplayer();
    this->executeBash = new ExecuteBash();
  }
  
  ~Profile()
  {
    delete user;
    delete help;
    delete em;
    delete responseDisplayer;
    delete executeBash;
  }
/*╭━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╮
  ┃                                                                              ┃
  ┃     Function: getCurrentSession() Description: This method will get the      ┃
  ┃     current session information. It will then print out the url, status      ┃
  ┃    code, and text. At last it will return a cpr::Response object with the    ┃
  ┃             request's information. Return: cpr::Response object              ┃
  ┃                                                                              ┃
  ╰━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╯
*/

  cpr::Response getCurrentSession(std::string input);

/*╭━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╮
  ┃                                                                              ┃
  ┃     Function: getAccountBalance() Description: This method will get the      ┃
  ┃     account's balance. It will then print out the url, status code, and      ┃
  ┃    text. At last it will return a cpr::Response object with the request's    ┃
  ┃                  information. Return: cpr::Response object                   ┃
  ┃                                                                              ┃
  ╰━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╯
*/

  cpr::Response getAccountBalance(std::string input);

/*╭━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╮
  ┃                                                                              ┃
  ┃    Function: blockAccount() Description: This method will ask the user to    ┃
  ┃    provide a new steam trade link. Then it will automatically update the     ┃
  ┃          trade link on Bitskins' side. Return: cpr::Response object          ┃
  ┃                                                                              ┃
  ╰━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╯
*/

  void updateTradeLink(std::string input);

/*╭━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╮
  ┃                                                                              ┃
  ┃      Function: blockAccount() Description: This method will ask for the      ┃
  ┃    user's steam username, password, and Bitskins API Key. When request is    ┃
  ┃         made, the user's Bitskins account will be disabled. Return:          ┃
  ┃                            cpr::Response object.                             ┃
  ┃                                                                              ┃
  ╰━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╯
*/

  cpr::Response blockAccount(std::string input);

/*╭━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╮
  ┃                                                                              ┃
  ┃      Function: updateAccount() Description: This method allows users to      ┃
  ┃     update their bitskins account details. Return: cpr::Response object.     ┃
  ┃                                                                              ┃
  ╰━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╯
*/

  cpr::Response updateAccount(std::string input);

/*╭━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╮
  ┃                                                                              ┃
  ┃    Function: userLogin() Description: This method will ask for the user's    ┃
  ┃     Bitskins API key. Inputs will be stored in a UserCredentials pointer     ┃
  ┃      object. At last it will return the UserCredentials pointer object.      ┃
  ┃                           Return: UserCredentials*                           ┃
  ┃                                                                              ┃
  ╰━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╯
*/

  UserCredentials* userLogin();


//          ╭---------------------------------------------------------╮
//          |                                                         |
//          |  Function: updateUserAPIKey() Description: This method  |
//          |         allows users to updated their api keys.         |
//          |                                                         |
//          ╰---------------------------------------------------------╯
  //
  bool updateUserAPIKey();
};
#endif // !PROFILE_H
