#include <cstdlib>
#include <stdlib.h>
#include <string>
#pragma once
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

    void setUsername(std::string username);
    void setPassword(std::string password);
    void setAPIKey(std::string APIKey);
    std::string getUsername();
    std::string getPassword(); 
    std::string getAPIKey(); 
  private:
    std::string Username;
    std::string Password;
    std::string APIKey;
};

