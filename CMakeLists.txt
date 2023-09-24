include(FetchContent)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git
                         GIT_TAG 2553fc41450301cd09a9271c8d2c3e0cf3546b73)
FetchContent_MakeAvailable(cpr)                       
FetchContent_Declare(MemPlumber GIT_REPOSITORY https://github.com/seladb/MemPlumber
                                GIT_TAG ff04d339b034c40f72e09653c6a0340c0bb05d3b)
FetchContent_MakeAvailable(MemPlumber)
cmake_minimum_required(VERSION 3.13.4)
set(CMAKE_CXX_STANDARD 17)
project(Bitskin-UI VERSION 1.0)
add_executable(${PROJECT_NAME} main.cxx)
find_package(nlohmann_json 3.2.0 REQUIRED)
add_subdirectory(
  src
  submodules/MemPlumber
)
target_link_libraries(${PROJECT_NAME} 
  PRIVATE src 
  PRIVATE cpr::cpr
  PRIVATE nlohmann_json::nlohmann_json
  PUBLIC memplumber
)
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_BINARY_DIR})
target_include_directories(${PROJECT_NAME}
  PUBLIC src
  PUBLIC ${PROJECT_BINARY_DIR}
)
target_link_directories(${PROJECT_NAME}
  PRIVATE src
)
