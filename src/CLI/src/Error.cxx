#include <stdio.h>
#include <stdlib.h>
#include "../header/Error.h"
using json = nlohmann::json;

bool errormap::checkErrorResponse(json j)
{
  if(j.contains("code"))
  {
    std::string ErrorMessage = j["code"];
    std::cout << this->errorMap[ErrorMessage] << "\n";
    return true;
  }
  return false;
}
