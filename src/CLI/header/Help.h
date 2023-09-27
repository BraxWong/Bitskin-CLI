#include <stdlib.h>
#include <cstdlib>
#include <stdio.h>
#include <string>
#pragma once

class Help
{
  public:
    ~Help()
    {
      delete this;
    }
    void showHelp(bool fromHelpPage, std::string command = "NONE");
};
