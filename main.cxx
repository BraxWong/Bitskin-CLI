#include "src/CLI/header/MainMenu.h"
#include "src/Account/header/Profile.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

int main() {
  CLI *cli = new CLI();
  cli->showCLIGreetings();
  Profile* profile = new Profile();
  profile->getCurrentSession();
  return 0;
}
