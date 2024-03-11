#include "../header/Error.h"
#include <stdio.h>
#include <stdlib.h>
using json = nlohmann::json;

bool ERRORMAP::errormap::checkErrorResponse(json j) {
  if (j.contains("code")) {
    std::string ErrorMessage = j["code"];
    if (this->errorMap.find(ErrorMessage) != this->errorMap.end()) {
      std::cout << this->errorMap[ErrorMessage] << "\n";
      return true;
    }
  }
  std::cout << "Error code " << j["code"]
            << " is not recognized. Please contact BitSkins Customer Service "
               "For More Information.\n";
  return false;
}
