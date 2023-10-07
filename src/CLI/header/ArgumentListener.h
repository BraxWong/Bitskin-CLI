#ifndef ARGUMENTLISTENER_H 
#define ARGUMENTLISTENER_H
#include <iostream>
#include <string>
#include <nlohmann/json.hpp>
using json = nlohmann::json;
class ArgumentListener {
  public:
    bool displayArgumentInfoOnly(json j, std::string input);
};
#endif
