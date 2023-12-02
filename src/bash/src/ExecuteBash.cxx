#include "../header/ExecuteBash.h"
#include <initializer_list>
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <sstream>

bool ExecuteBash::executeBashScript(std::string url, std::string APIKey, std::vector<std::string> keys, std::vector<std::string> values, std::vector<std::string> dataTypes)
{
  std::stringstream command;
  std::vector<std::string> args = this->createBashCMD(url, APIKey, keys, values, dataTypes);
  for(const std::string& arg: args)
  {
    command << arg << " ";
  }
  FILE* pipe = popen(command.str().c_str(), "r");
  if (!pipe)
  {
    throw std::runtime_error("popen() failed!");
  }

  std::ostringstream output;
  char buffer[128];
  while (fgets(buffer, sizeof(buffer), pipe) != nullptr)
  {
    output << buffer;
  }

  // Close the pipe
  pclose(pipe);

  //Return the captured output as a string
  std::string str = output.str();
  std::string res;
  for(int i = 0; i < str.length(); ++i)
  {
    if(str[i] == '{')
    {
      for(int j = i; j < str.length(); ++j)
      {
        res += str[j];
      }
      break;
    }
  }
  std::cout << res << "\n";
  return false;
}

std::vector<std::string> ExecuteBash::createBashCMD(std::string url, std::string APIKey, std::vector<std::string> keys, std::vector<std::string> values, std::vector<std::string> dataTypes)
{
  std::string curlURL = "curl -s " + url;
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
