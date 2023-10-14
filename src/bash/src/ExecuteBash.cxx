#include "../header/ExecuteBash.h"
#include <iostream>
#include <stdio.h>

bool ExecuteBash::bashCurl(std::string url, std::string APIKey, std::string key, std::string value)
{
  system("chmod +x ../testing.sh");
  std::string command = "../testing.sh " + url + " " + APIKey + " " + key + " " + value;
  if(system(command.c_str()) == 0)
  {
    return true;
  }
  return false;
}
