include(FetchContent)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git
                         GIT_TAG 2553fc41450301cd09a9271c8d2c3e0cf3546b73)
FetchContent_MakeAvailable(cpr)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.4.0
)
FetchContent_MakeAvailable(Catch2)

FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz)
FetchContent_MakeAvailable(json)
cmake_minimum_required(VERSION 3.13.4)
set(CMAKE_CXX_STANDARD 17)
project(Bitskin-UI VERSION 1.0)
#Uncomment the following line if you want to run the program
#add_executable(${PROJECT_NAME} main.cxx)
#Uncomment the following line if you want to run all the tests
add_executable(${PROJECT_NAME} tests/testmain.cxx)
add_subdirectory(
  src
  submodules/MemPlumber
)
target_link_libraries(${PROJECT_NAME}
  PRIVATE src
  PRIVATE cpr::cpr
  PRIVATE nlohmann_json::nlohmann_json
  PRIVATE Catch2::Catch2WithMain
)
target_include_directories(${PROJECT_NAME}
  PUBLIC src
  PUBLIC ${PROJECT_BINARY_DIR}
)
target_link_directories(${PROJECT_NAME}
  PRIVATE src
)
