cmake_minimum_required(VERSION 3.20)

project(Alchemy-Engine)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED 20)


include_directories("${PROJECT_BINARY_DIR}")
add_definitions(-DUNICODE -D_UNICODE)

if(${CMAKE_BUILD_TYPE} STREQUAL "Debug")
    option(DEBUG "DEBUG MODE" ON)
else()
    option(RELEASE "RELEASE MODE" ON)
endif()

set(ENGINE_MODE ${CMAKE_BUILD_TYPE})
if(${ENGINE_MODE} STREQUAL "")
    option(CLIENT "CLIENT MODE" ON)
elseif(${ENGINE_MODE} STREQUAL "CLIENT")
    option(CLIENT "CLIENT MODE" ON)
elseif(${ENGINE_MODE} STREQUAL "EDITOR")
    option(EDITOR "EDITOR MODE" ON)
elseif(${ENGINE_MODE} STREQUAL "SERVER")
    option(SERVER "SERVER MODE" ON)
endif()

set(ENGINE_ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR})

configure_file(config.h.in config.h)

add_subdirectory(Engine)

add_executable(Alchemy WIN32 "Engine/main.cc")

target_link_libraries(Alchemy PRIVATE
    Launcher
    Engine
    Misc
    Time
    Window
    HAL_Windows
)
