cmake_minimum_required(VERSION 3.12)

project(ftpServerWindow
  VERSION
    1.0
  DESCRIPTION
    "Qt/C++ based FTP Server"
  LANGUAGES
    CXX
)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if(CMAKE_VERSION VERSION_LESS "3.15.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

find_package(Qt5 COMPONENTS Widgets REQUIRED)

find_package(Qt5Core REQUIRED)

find_package(Qt5Network REQUIRED)

set(SRC_FILES
		main.cpp
		ftpServerWindow.cpp
		)

set(HEADER_FILES
		ftpServerWindow.h
		)
		
set(UI_FILES
		ftpServerWindow.ui
		)
		
#set(QRC_FILES
#		icons.qrc
#		)

add_executable(${PROJECT_NAME} ${SRC_FILES} ${HEADER_FILES} ${UI_FILES})

add_definitions(-DQT_NO_VERSION_TAGGING)

target_link_libraries(${PROJECT_NAME} ${CMAKE_BINARY_DIR}/QFtpServerLib/libQFtpServerLib.a)

target_link_libraries(${PROJECT_NAME} -lssl)

target_link_libraries(${PROJECT_NAME} Qt5::Widgets Qt5::Network Qt5::Core)
#qt5_use_modules(${PROJECT_NAME} Core Network)

#ADD_LIBRARY(QFtpServerLib_1 STATIC IMPORTED)
#SET_TARGET_PROPERTIES(QFtpServerLib_1 PROPERTIES IMPORTED_LOCATION ${CMAKE_BINARY_DIR}/QFtpServerLib/libQFtpServerLib.a)



include_directories(. ../QFtpServerLib)


