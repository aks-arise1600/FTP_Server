cmake_minimum_required(VERSION 3.12)

project(QFtpServerLib VERSION 1.0.1 DESCRIPTION "QFtpServerLib FTP-Server")

find_package(Qt5 COMPONENTS Widgets REQUIRED)

find_package(Qt5Core REQUIRED)


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

set(QRC_FILES
	certificates.qrc
	)

add_library(${PROJECT_NAME} ${SRC_FILES} ${QRC_FILES} )

set_target_properties(${PROJECT_NAME} PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION ${PROJECT_VERSION_MAJOR}
    PUBLIC_HEADER api/${PROJECT_NAME}.h)
    
add_definitions(-DQT_NO_VERSION_TAGGING)

target_link_libraries(${PROJECT_NAME} Qt5::Widgets ssl)
qt5_use_modules(${PROJECT_NAME} Core Network)

include_directories(.)
