cmake_minimum_required(VERSION 3.5)

project(PetShelterQt VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Qt Libraries
find_package(Qt6 REQUIRED COMPONENTS Widgets)

# Identifying Files
set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        Entities.h
        Services.h
        resources.qrc
)

add_executable(PetShelterQt
    ${PROJECT_SOURCES}
    ShelterLogic.h
    addpetdialog.h
    addpetdialog.cpp
)

# Connect Libraries
target_link_libraries(PetShelterQt PRIVATE Qt6::Widgets)

# Icon Settings
set_target_properties(PetShelterQt PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
)
