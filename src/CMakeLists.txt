add_library(src 
  CLI/src/MainMenu.cxx 
  CLI/src/UserCredentials.cxx
  CLI/src/Help.cxx
  CLI/src/Listener.cxx
  CLI/src/Error.cxx
  CLI/src/ResponseDisplayer.cxx
  bash/src/ExecuteBash.cxx
  Account/src/APIKey.cxx
  Account/src/Profile.cxx 
  Account/src/Affiliate.cxx
  Config/src/CurrencyRates.cxx
  Config/src/FeePlans.cxx
  Config/src/PlatformStatus.cxx
  Market/src/MarketEnum.cxx
  Market/src/Pricing.cxx
)
include(FetchContent)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git
                         GIT_TAG 2553fc41450301cd09a9271c8d2c3e0cf3546b73) # The commit hash for 1.10.x. Replace with the latest from: https://github.com/libcpr/cpr/releases
FetchContent_MakeAvailable(cpr)
find_package(nlohmann_json 3.2.0 REQUIRED)
target_link_libraries(src 
  PRIVATE cpr::cpr
  PRIVATE nlohmann_json::nlohmann_json
)
