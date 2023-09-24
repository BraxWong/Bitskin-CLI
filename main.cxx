#include "src/CLI/header/MainMenu.h"
#include "src/Account/header/Profile.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
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
  UserCredentials* user = profile->userLogin();
  profile->getCurrentSession();
  profile->getAccountBalance();
  delete cli;
  delete profile->user;
  delete profile;
  delete listener;
  size_t memLeakCount;
  uint64_t memLeakSize;
  MemPlumber::memLeakCheck(memLeakCount, memLeakSize, true);
  std::cout << "Number of leaked objects:"+ std::to_string(int(memLeakCount)) + "\nTotal amount of memory leaked:" + std::to_string(int(memLeakSize)) + "[bytes]\n";
  return 0;
}
