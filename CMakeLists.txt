cmake_minimum_required(VERSION 3.16)
project(Colosseum LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

find_package(Qt6 REQUIRED COMPONENTS Core Widgets)

option(BUILD_GUI "Build the GUI" OFF) 

add_library(lib STATIC
    colosseum/lib/src/engine_manager.cpp
    colosseum/lib/src/engine_option.cpp
    colosseum/lib/src/engine.cpp
    colosseum/lib/src/match.cpp
    colosseum/lib/src/timecontrol.cpp
    colosseum/lib/src/tournament.cpp
)

target_include_directories(lib PRIVATE
    colosseum/lib/include
)

target_link_libraries(lib PRIVATE Qt6::Core)

add_executable(colosseum-cli 
    colosseum/cli/main.cpp
)

target_include_directories(colosseum-cli PRIVATE
    colosseum/lib/include
    colosseum/cli/include
)

target_link_libraries(colosseum-cli PRIVATE lib Qt6::Core)

if(BUILD_GUI)
    add_executable(colosseum
        colosseum/gui/main.cpp
    )

    target_include_directories(colosseum PRIVATE
    colosseum/lib/include
    colosseum/gui/include
    )

    target_link_libraries(colosseum PRIVATE lib Qt6::Core Qt6::Widgets)
endif()