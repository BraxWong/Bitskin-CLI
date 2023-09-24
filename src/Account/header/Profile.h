#include <cpr/cpr.h>
#include "../../CLI/header/UserCredentials.h"
#include <cstdlib>
#include <stdlib.h>
#include <string>
#include <nlohmann/json.hpp>
#pragma once

class Profile {
public:
  UserCredentials* user;
/*╭━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╮
  ┃                                                                              ┃
  ┃     Function: getCurrentSession() Description: This method will get the      ┃
  ┃     current session information. It will then print out the url, status      ┃
  ┃    code, and text. At last it will return a cpr::Response object with the    ┃
  ┃             request's information. Return: cpr::Response object              ┃
  ┃                                                                              ┃
  ╰━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╯
*/

  cpr::Response getCurrentSession();

/*╭━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╮
  ┃                                                                              ┃
  ┃     Function: getAccountBalance() Description: This method will get the      ┃
  ┃     account's balance. It will then print out the url, status code, and      ┃
  ┃    text. At last it will return a cpr::Response object with the request's    ┃
  ┃                  information. Return: cpr::Response object                   ┃
  ┃                                                                              ┃
  ╰━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╯

*/
  cpr::Response getAccountBalance();

/*╭━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╮
  ┃                                                                              ┃
  ┃    Function: blockAccount() Description: This method will ask the user to    ┃
  ┃    provide a new steam trade link. Then it will automatically update the     ┃
  ┃          trade link on Bitskins' side. Return: cpr::Response object          ┃
  ┃                                                                              ┃
  ╰━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╯
*/

  cpr::Response updateTradeLink();

/*╭━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╮
  ┃                                                                              ┃
  ┃      Function: blockAccount() Description: This method will ask for the      ┃
  ┃    user's steam username, password, and Bitskins API Key. When request is    ┃
  ┃         made, the user's Bitskins account will be disabled. Return:          ┃
  ┃                            cpr::Response object.                             ┃
  ┃                                                                              ┃
  ╰━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╯
*/

  cpr::Response blockAccount();

/*╭━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╮
  ┃                                                                              ┃
  ┃      Function: updateAccount() Description: This method allows users to      ┃
  ┃     update their bitskins account details. Return: cpr::Response object.     ┃
  ┃                                                                              ┃
  ╰━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╯
*/

  cpr::Response updateAccount();

/*╭━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╮
  ┃                                                                              ┃
  ┃    Function: userLogin() Description: This method will ask for the user's    ┃
  ┃    steam username, password, and Bitskins API key. Inputs will be stored     ┃
  ┃       in a UserCredentials pointer object. At last it will return the        ┃
  ┃           UserCredentials pointer object. Return: UserCredentials*           ┃
  ┃                                                                              ┃
  ╰━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╯
*/

  UserCredentials* userLogin();
};
