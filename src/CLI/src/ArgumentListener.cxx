#include "../header/ArgumentListener.h"
#include <iostream>
#include <stdio.h>
#include <unistd.h>

bool ArgumentListener::displayArgumentInfoOnly(json j, std::string input)
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
