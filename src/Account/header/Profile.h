#include <cpr/cpr.h>
#include <cstdlib>
#include <stdlib.h>
#include <string>

class Profile {
public:
  cpr::Response getCurrentSession(std::string APIKEY);
};
