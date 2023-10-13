#ifndef HELP_H
#define HELP_H
#include <stdlib.h>
#include <cstdlib>
#include <stdio.h>
#include <string>

class Help
{
  public:
    bool showHelp(bool fromHelpPage, std::string command = "NONE");
};
#endif // !HELP_H
