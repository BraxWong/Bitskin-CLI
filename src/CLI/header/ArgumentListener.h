#ifndef ARGUMENTLISTENER_H 
#define ARGUMENTLISTENER_H
#include <iostream>
#include <string>
#include <nlohmann/json.hpp>
using json = nlohmann::json;
class ArgumentListener {
  public:

/*╭━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╮
  ┃                                                                              ┃
  ┃      Function: displayArgumentInfoOnly() Description: This method will       ┃
  ┃    display the specific information being passed in. For example, if -arg    ┃
  ┃   wbalance is present when called the -session command, only the wbalance    ┃
  ┃                section of the json object will be displayed.                 ┃
  ┃                                                                              ┃
  ╰━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╯
*/

    bool displayArgumentInfoOnly(json j, std::string input);
};
#endif
