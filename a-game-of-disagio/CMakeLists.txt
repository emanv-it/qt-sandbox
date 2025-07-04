cmake_minimum_required(VERSION 3.16)

project(A-Game-of-Disagio)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5Widgets REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

add_executable(a-game-of-disagio src/main.cpp
        src/handlers/levelhandler.cpp src/handlers/levelhandler.h
        src/handlers/schemahandler.cpp src/handlers/schemahandler.h
        src/handlers/tilehandler.cpp src/handlers/tilehandler.h
        src/models/schema.cpp src/models/schema.h
        src/ui/schema/schemalayout.cpp src/ui/schema/schemalayout.h
        src/ui/schema/schemawidget.cpp src/ui/schema/schemawidget.h
        src/ui/schema/tilebutton.cpp src/ui/schema/tilebutton.h
        src/ui/side/sidewidget.cpp src/ui/side/sidewidget.h
        src/ui/mainwindow.cpp src/ui/mainwindow.h
        src/ui/mainwindow.ui
        src/ui/windowlayout.cpp src/ui/windowlayout.h
        src/exceptions.h
)
target_link_libraries(a-game-of-disagio Qt5::Widgets)