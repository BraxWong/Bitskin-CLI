#ifndef RESPONSEDISPLAYER_H 
#define RESPONSEDISPLAYER_H
#include "Error.h"
#include <iostream>
#include <string>
#include <nlohmann/json.hpp>
#include <cpr/cpr.h>
using json = nlohmann::json;

class ResponseDisplayer {
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

    bool displayHttpResponse(ERRORMAP::errormap* em, cpr::Response response, std::string input);
};
#endif
