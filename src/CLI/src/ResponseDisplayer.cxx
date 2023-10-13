#include "../header/ResponseDisplayer.h"
#include <iostream>
#include <stdio.h>
#include <unistd.h>

bool ResponseDisplayer::displayArgumentInfoOnly(json j, std::string input)
{
  //Find out if an argument is present within the command
  if(input.find("-arg") == std::string::npos)
  {
    return false;
  }

  //Extract the argument and store in arg
  std::string arg = input.substr(input.find("-arg") + 5);

  //Check if the argument provided is valid. If so, print out the information needed.
  if(j.contains(arg))
  {
    std::cout << j[arg] << "\n"; 
    return true;
  }

  //Argument provided is invalid. Print out the error message.
  std::cout << "Invalid Argument. Please check the help page for more information.\n";
  return false;
}

bool ResponseDisplayer::displayHttpResponse(ERRORMAP::errormap* em, cpr::Response response, std::string input)
{
  if(response.error)
  {
    return false;
  }
  if(response.text[0] == '{')
  {
    json j = json::parse(response.text);
    if(!em->checkErrorResponse(j) && !this->displayArgumentInfoOnly(j, input))
    {
      std::cout << response.url << "\n" << j.dump(4) << "\n";
    }
  }
  else 
  {
    std::cout << "No Response\n";
    return true;
  }
  return true;
}
