set(PROJECTNAME QTMessager)

set(PROJECTNAME QTMessager)

cmake_minimum_required(VERSION 3.5)
project(${PROJECTNAME})
# -std=c++11

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
set(CMAKE_PREFIX_PATH "D:/Program/Qt/5.11.1/msvc2015/")
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_CONFIGURATION_TYPES "Release" CACHE STRING "" FORCE)
set(CMAKE_CONFIGURATION_TYPES "Debug" CACHE STRING "" FORCE)
set(CMAKE_BUILD_TYPE Release)
find_package(Qt5Core REQUIRED)
find_package(Qt5Network REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Sql REQUIRED)
find_package(Qt5Xml REQUIRED)
find_package(Qt5PrintSupport REQUIRED)


set(SOURCE_FILES
        main.cpp
        dialog.cpp
        chatunit/ChatUnit.cpp
        chatunit/ChatUnit.h
        chatunit/ChatServer.cpp
        chatunit/ChatServer.h
        entity/Client.cpp
        entity/Client.h
        entity/Request.cpp
        entity/Request.h
        entity/requests/GetClientsRequest.cpp
        entity/requests/GetClientsRequest.h
        entity/responces/GetClientsResponse.cpp
        entity/responces/GetClientsResponse.h
        entity/Response.cpp
        entity/Response.h
        chatunit/ChatClient.cpp
        chatunit/ChatClient.h
        request_executors/RequestExecutor.cpp request_executors/RequestExecutor.h)
add_executable(QTMessager ${SOURCE_FILES})

target_link_libraries(${PROJECTNAME} Qt5::Widgets)
target_link_libraries(${PROJECTNAME} Qt5::Core)
target_link_libraries(${PROJECTNAME} Qt5::Network)
target_link_libraries(${PROJECTNAME} Qt5::Sql)
target_link_libraries(${PROJECTNAME} Qt5::Xml)