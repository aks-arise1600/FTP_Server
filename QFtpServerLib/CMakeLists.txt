cmake_minimum_required(VERSION 3.12)

project(QFtpServerLib VERSION 1.0.1 DESCRIPTION "QFtpServerLib FTP-Server")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

find_package(Qt5Core REQUIRED)

find_package(Qt5Network REQUIRED)


set (SRC_FILES 
	dataconnection.cpp
    ftpcommand.cpp
    ftpcontrolconnection.cpp
    ftplistcommand.cpp
    ftpretrcommand.cpp
    ftpserver.cpp
    ftpstorcommand.cpp
    sslserver.cpp
    )
    
set (HEADERS
        qftpserverlib_global.h 
    dataconnection.h 
    ftpcommand.h 
    ftpcontrolconnection.h 
    ftplistcommand.h 
    ftpretrcommand.h 
    ftpserver.h 
    ftpstorcommand.h 
    sslserver.h
	)

set(QRC_FILES
	certificates.qrc
	)

add_library(${PROJECT_NAME} ${SRC_FILES} ${HEADERS} ${QRC_FILES} )

set_target_properties(${PROJECT_NAME} PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION ${PROJECT_VERSION_MAJOR}
    PUBLIC_HEADER api/${PROJECT_NAME}.h)
    
add_definitions(-DQT_NO_VERSION_TAGGING)

target_link_libraries(${PROJECT_NAME} Qt5::Widgets Qt5::Network)
#qt5_use_modules(${PROJECT_NAME} Core Network)

include_directories(.)
