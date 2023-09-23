add_library(src 
  CLI/src/MainMenu.cxx 
  CLI/src/UserCredentials.cxx
  CLI/src/Help.cxx
  CLI/src/Listener.cxx
  Account/src/Profile.cxx 
)
include(FetchContent)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git
                         GIT_TAG 3020c34ae2b732121f37433e61599c34535e68a8) # The commit hash for 1.10.x. Replace with the latest from: https://github.com/libcpr/cpr/releases
FetchContent_MakeAvailable(cpr)
find_package(nlohmann_json 3.2.0 REQUIRED)
target_link_libraries(src 
  PRIVATE cpr::cpr
  PRIVATE nlohmann_json::nlohmann_json
)
