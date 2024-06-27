cmake_minimum_required(VERSION 3.12)

project(FTP-Server)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(CMAKE_VERSION VERSION_LESS "3.12.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

add_subdirectory(QFtpServerLib)
add_subdirectory(ftpServerWindow)
