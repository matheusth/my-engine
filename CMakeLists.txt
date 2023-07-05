cmake_minimum_required(VERSION 3.6)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(MyEngine)

option(PLATFORM_WINDOWS "Build for windows?" OFF)

if (PLATFORM_WINDOWS)
    list(APPEND COMPILE_DEFS "PLATFORM_WINDOWS")
    list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/src/Platforms/Windows")
    list(APPEND EXTRA_LIBS gdi3 user32)
    list(APPEND SOURCE_FILES src/Platforms/Windows/WindowsWindow.h src/Platforms/Windows/WindowsWindow.cpp)
else ()
    list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/src/Platforms/Linux")
    list(APPEND EXTRA_LIBS X11)
    list(APPEND SOURCE_FILES src/Platforms/Linux/LinuxWindow.h src/Platforms/Linux/LinuxWindow.cpp)
endif ()

list(APPEND SOURCE_FILES src/Core/Engine.h src/Core/Engine.cpp src/Core/EntryPoint.cpp src/Core/MyWindow.h)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})
target_compile_definitions(${PROJECT_NAME} PUBLIC ${COMPILE_DEFS} PUBLIC PROJECT_DIR="${PROJECT_SOURCE_DIR}")
target_include_directories(${PROJECT_NAME} PUBLIC ${EXTRA_INCLUDES})
TARGET_LINK_LIBRARIES(${PROJECT_NAME} PUBLIC ${EXTRA_LIBS})