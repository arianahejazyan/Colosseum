cmake_minimum_required(VERSION 3.25)

project(Colosseum LANGUAGES C CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# === Sources ===
file(GLOB_RECURSE LIB_SOURCES src/lib/*.cpp)
file(GLOB_RECURSE CLI_SOURCES src/cli/*.cpp)

# === Libraries ===
add_library(lib STATIC ${LIB_SOURCES})
target_compile_features(lib PUBLIC cxx_std_23)
target_include_directories(lib PUBLIC src)

add_library(cli STATIC ${CLI_SOURCES})
target_compile_features(cli PUBLIC cxx_std_23)
target_link_libraries(cli PUBLIC lib)
target_include_directories(cli PUBLIC src)

# === Single executable ===
add_executable(colosseum src/colosseum.cc)
target_link_libraries(colosseum PRIVATE cli)
