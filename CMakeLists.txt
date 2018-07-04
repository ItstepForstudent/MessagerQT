set(PROJECTNAME QTMessager)

cmake_minimum_required(VERSION 3.5)
project(${PROJECTNAME})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_PREFIX_PATH "/Users/virus/Qt/5.11.1/clang_64/")
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

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
        )
add_executable(QTMessager ${SOURCE_FILES})

target_link_libraries(${PROJECTNAME} Qt5::Widgets)
target_link_libraries(${PROJECTNAME} Qt5::Core)
target_link_libraries(${PROJECTNAME} Qt5::Network)
target_link_libraries(${PROJECTNAME} Qt5::Sql)
target_link_libraries(${PROJECTNAME} Qt5::Xml)