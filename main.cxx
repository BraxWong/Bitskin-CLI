#include "src/CLI/header/MainMenu.h"
#include "src/Account/header/Profile.h"
#include "src/CLI/header/Listener.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <nlohmann/json.hpp>

int main() {
  CLI *cli = new CLI();
  cli->showCLIGreetings();
  Profile* profile = new Profile();
  profile->userLogin();
  Listener* listener = new Listener(profile);
  listener->listenCommand();
  delete cli;
  delete profile;
  delete listener;
  return 0;
}
