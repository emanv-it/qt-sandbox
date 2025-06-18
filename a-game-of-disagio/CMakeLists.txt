cmake_minimum_required(VERSION 3.16)

project(A-Game-of-Disagio)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5Widgets REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

add_executable(a-game-of-disagio src/main.cpp
        src/exceptions.h
        src/models/schema.cpp src/models/schema.h
        src/handlers/schemahandler.cpp src/handlers/schemahandler.h
        src/ui/button.cpp src/ui/button.h
        src/ui/centrallayout.cpp src/ui/centrallayout.h
        src/ui/mainwindow.cpp src/ui/mainwindow.h
        src/ui/mainwindow.ui
)
target_link_libraries(a-game-of-disagio Qt5::Widgets)