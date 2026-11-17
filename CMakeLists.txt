cmake_minimum_required(VERSION 3.10)
project(Colosseum LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# === BUILD OPTIONS ===
option(BUILD_CLI "Build CLI Tool" ON)
option(BUILD_APP "Build GUI Application" ON)

# === UTILITY LIBRARY ===
file(GLOB_RECURSE UTILITY_SOURCES
    "src/utility/*.cpp"
)

# Create lib library
add_library(utility STATIC ${UTILITY_SOURCES})

# Include directories for lib headers
target_include_directories(utility PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/utility
)

# === SHARED LIBRARY ===
file(GLOB_RECURSE LIB_SOURCES
    "src/lib/*.cpp"
)

file(GLOB_RECURSE LIB_HEADERS
    "src/lib/*.h"
    "src/lib/*/*.h"
    "src/lib/*/*/*.h"
)

# Create lib library
add_library(lib STATIC ${LIB_SOURCES})

# Link libraries
target_link_libraries(lib utility)

# Include directories for lib headers
target_include_directories(lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/lib)

# === CLI LIBRARY ===
file(GLOB_RECURSE CLI_SOURCES
    "src/cli/*.cpp"
)

# Create app library
add_library(cli STATIC ${CLI_SOURCES})

target_link_libraries(cli lib utility)

# Include directories for cli headers
target_include_directories(cli PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/cli
    ${CMAKE_CURRENT_SOURCE_DIR}/src/lib
)

# === APP LIBRARY ===
file(GLOB_RECURSE APP_SOURCES
    "src/app/*.cpp"
)

# Create app library
add_library(app STATIC ${APP_SOURCES})
target_link_libraries(app lib utility)

# Include directories for app headers
target_include_directories(app PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/app
)

# === CLI EXECUTABLE ===
if(BUILD_CLI)
    add_executable(colosseum-cli
        src/colosseum-cli.cc
    )
    target_link_libraries(colosseum-cli cli)
endif()

# === APP EXECUTABLE ===
if(BUILD_APP)
    add_executable(colosseum-app
        src/colosseum-app.cc
    )
    target_link_libraries(colosseum-app app)
endif()
