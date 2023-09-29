#include "src/CLI/header/MainMenu.h"
#include "src/Account/header/Profile.h"
#include "src/CLI/header/Listener.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <nlohmann/json.hpp>
#include <string>
#include "memplumber.h"


/*      ╭━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╮
        ┃                                                                ┃
        ┃ TODO:Free the Profile member object within the Listener class. ┃
        ┃                                                                ┃
        ╰━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╯
*/


/*        ╭━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╮
          ┃                                                            ┃
          ┃ NOTE:Need to start making destructors for all the classes. ┃
          ┃                                                            ┃
          ╰━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╯
*/

int main() {
  MemPlumber::start();
  CLI *cli = new CLI();
  cli->showCLIGreetings();
  Profile* profile = new Profile();
  profile->userLogin();
  Listener* listener = new Listener(profile);
  listener->listenCommand();
  MemPlumber::stopAndFreeAllMemory();
  return 0;
}
