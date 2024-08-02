cmake_minimum_required(VERSION 3.5)

project(testTaskRedSoft LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(testTaskRedSoft main.cpp
    app.h app.cpp)

include(GNUInstallDirs)
install(TARGETS testTaskRedSoft
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
