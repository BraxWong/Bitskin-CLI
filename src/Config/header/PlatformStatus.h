#ifndef PLATFORMSTATUS_H
#define PLATFORMSTATUS_H
#include <cpr/cpr.h>
#include "../../CLI//header/Help.h"
#include "../../CLI/header/Error.h"
#include "../../bash/header/ExecuteBash.h"
#include "../../CLI/header/ResponseDisplayer.h"
#include "../../Account/header/Profile.h"
#include <cstdlib>
#include <stdlib.h>
#include <string>
#include <nlohmann/json.hpp>

class PlatformStatus 
{
  public:
    Profile* profile;
    Help* help;
    ERRORMAP::errormap* em;
    ResponseDisplayer* responseDisplayer;

    PlatformStatus(Profile* profile)
    {
      this->profile = profile;
      this->help = this->profile->help;
      this->em = this->profile->em;
      this->responseDisplayer = new ResponseDisplayer();
    }
    
    ~PlatformStatus()
    {
      delete this->responseDisplayer;
    }
/*╭━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╮
  ┃                                                                              ┃
  ┃      Function: getPlatformStatus() Description: This method will return      ┃
  ┃      Bitskins' platform status. Including buy order, instant sell, and       ┃
  ┃    platform status. It will then return the cpr::Response object. Return:    ┃
  ┃                            cpr::Response object.                             ┃
  ┃                                                                              ┃
  ╰━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╯
*/

    cpr::Response getPlatformStatus(std::string input);
};


/*╭━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╮
  ┃                                                                              ┃
  ┃    ENUM: Global_Platform_Status Description: Use to determine the status     ┃
  ┃       of the BItskins service, including: buy order, instant sell, and       ┃
  ┃                               platform status.                               ┃
  ┃                                                                              ┃
  ╰━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╯
*/

enum Global_Platform_Status
{
  loading = -2,
  offline = -1,
  steam_down = 0,
  active = 1
};


/*╭━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╮
  ┃                                                                              ┃
  ┃   Function: getGlobalPlatformStatusString() Description: This method will    ┃
  ┃               return Bitskins' global platform status string.                ┃
  ┃                                                                              ┃
  ╰━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╯
*/

std::string getGlobalPlatformStatusString(Global_Platform_Status gps);

#endif
 
