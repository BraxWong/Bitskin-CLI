#ifndef USERCREDENTIALS_H
#define USERCREDENTIALS_H
#define VALID_API_KEY_LENGTH 64;
#include <cstdlib>
#include <stdlib.h>
#include <string>
/*                   ╭━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╮
                     ┃                                      ┃
                     ┃ UserCredentials Class Documentations ┃
                     ┃                                      ┃
                     ╰━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╯
*/

class UserCredentials
{
  public:
/*               ╭━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╮
                 ┃                                               ┃
                 ┃ Getters and Setters for UserCredentials Class ┃
                 ┃                                               ┃
                 ╰━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╯
*/
    bool setAPIKey(std::string APIKey);
    void setAuthToken(std::string AuthToken);
    std::string getAPIKey(); 
    std::string getAuthToken();
  private:
    bool checkAPIKeyValidity(std::string APIKey);
    std::string APIKey;
    std::string authToken;
};
#endif // !USERCREDENTIALS_H