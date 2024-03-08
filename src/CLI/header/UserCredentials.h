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

class UserCredentials {
public:
  /*               ╭━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╮
                   ┃                                               ┃
                   ┃ Getters and Setters for UserCredentials Class ┃
                   ┃                                               ┃
                   ╰━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╯
  */

  void setAPIKey();
  void setAuthToken(std::string AuthToken);
  std::string getAPIKey();
  std::string getAuthToken();

private:
  std::string APIKey;
  std::string authToken;
};
#endif // !USERCREDENTIALS_H
