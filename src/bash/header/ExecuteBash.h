#ifndef EXECUTEBASH_H
#define EXECUTEBASH_H
#include <cstdlib>
#include <stdlib.h>
#include <string>
class ExecuteBash
{
  public:
    bool bashCurl(std::string url, std::string APIKey, std::string key, std::string value);
};
#endif
