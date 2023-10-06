#include "../header/MainMenu.h"
#include <cpr/cpr.h>
#include <iostream>
#include <stdio.h>

void MAINMENU_H::CLI::showCLIGreetings() {
  std::cout << "────────────────────────────────────────────────────────────\n";
  std::cout << "              Welcome to Bitskins API V2 CLI\n";
  std::cout << "NOTICE: This software is not affliated with Bitskins itself "
               "besides using the API that is provided by Bitskins.\n";
  std::cout
      << "The creator of Bitskins API V2 CLI: Brax Wong and BItskins will not "
         "be liable for any monetary lost due to the usage of this program\n";
}
