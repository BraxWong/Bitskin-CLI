#ifndef USERCREDENTIALS_H
#define USERCREDENTIALS_H
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

    void setAPIKey(std::string APIKey);
    std::string getAPIKey(); 
  private:
    std::string APIKey;
};
#endif // !USERCREDENTIALS_H
