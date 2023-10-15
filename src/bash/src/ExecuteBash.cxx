#include "../header/ExecuteBash.h"
#include <initializer_list>
#include <iostream>
#include <stdio.h>

bool ExecuteBash::executeBashScript(std::string url, std::string APIKey, std::vector<std::string> keys, std::vector<std::string> values, std::vector<std::string> dataTypes)
{
  std::stringstream command;
  std::vector<std::string> args = this->createBashCMD(url, APIKey, keys, values, dataTypes);
  for(const std::string& arg: args)
  {
    command << arg << " ";
  }
  if(system(command.str().c_str()) == 0)
  {
    system("echo \"\"");
    return true;
  }
  return false;
}

std::vector<std::string> ExecuteBash::createBashCMD(std::string url, std::string APIKey, std::vector<std::string> keys, std::vector<std::string> values, std::vector<std::string> dataTypes)
{
  std::string curlURL = "curl " + url;
  std::string post = "-X POST";
  std::string contentType = "-H 'content-type: application/json'";
  std::string apiKey = "-H 'x-apikey: " + APIKey + "'";
  std::string dataRaw = "--data-raw '{";
  for(int i = 0; i < keys.size(); ++i)
  {
    dataRaw += "\"" + keys[i];
    if(dataTypes[i] == "String")
    {
      dataRaw += "\"':'\"" + values[i] + "\"";
    }
    else 
    {
      dataRaw +=  "\"':'" + values[i];
    }
    if(i != keys.size() - 1)
    {
      dataRaw += ",";
    }
    else 
    {
      dataRaw += "}'";
    }
  }
  std::vector<std::string> vectorArgs = {curlURL, post, contentType, apiKey, dataRaw};
  return vectorArgs;
}
