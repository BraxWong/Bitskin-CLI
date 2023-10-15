#ifndef EXECUTEBASH_H
#define EXECUTEBASH_H
#include <cstdlib>
#include <stdlib.h>
#include <string>
#include <initializer_list>
#include <sstream>
#include <vector>
class ExecuteBash
{
  public:

/*╭━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╮
  ┃                                                                              ┃
  ┃       Function: executeBashScript() Description: This method will call       ┃
  ┃   createBashCMD() to create a vector of Bash command string. It will then    ┃
  ┃     be passed into system() in order to execute them as Bash command. If     ┃
  ┃     the command was executed successfully, the method will return true.      ┃
  ┃                     Else, the method will return false.                      ┃
  ┃                                                                              ┃
  ╰━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╯
*/

  bool executeBashScript(std::string url, std::string APIKey, std::vector<std::string> keys, std::vector<std::string> values, std::vector<std::string> dataTypes);
  

/*╭━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╮
  ┃                                                                              ┃
  ┃   Function: createBashCMD() Description: This method will create a vector    ┃
  ┃             of Bash command using the arguments being passed in.             ┃
  ┃                                                                              ┃
  ╰━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╯
*/

  std::vector<std::string> createBashCMD(std::string url, std::string APIKey, std::vector<std::string> keys, std::vector<std::string> values, std::vector<std::string> dataTypes);
};
#endif
