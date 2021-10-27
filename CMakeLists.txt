cmake_minimum_required(VERSION 3.16.3)
project(advanced_programminig_1)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

file(GLOB client_src src/server/IOS/*.cpp src/server/client/*/*/*.cpp src/server/client/*/*/*/*.cpp src/server/client/*/*.cpp src/server/client/*.cpp src/server/tcpServer/TCPServer.cpp src/server/tcpServer/ThreadList.cpp src/server/serverCommandLineInterface/*/*.cpp src/server/serverCommandLineInterface/*/*/*.cpp src/server/serverCommandLineInterface/*.cpp src/classifier/*.cpp src/classifier/*/*.cpp)
file(GLOB server_src src/server/tcpServer/*.cpp src/server/IOS/*.cpp src/server/serverCommandLineInterface/*/*.cpp src/server/serverCommandLineInterface/*/*/*.cpp src/server/serverCommandLineInterface/*.cpp src/classifier/*.cpp src/classifier/*/*.cpp)
add_executable(client ${client_src})
add_executable(server ${server_src})


file(GLOB testClient_src src/server/IOS/*.cpp src/server/serverCommandLineInterface/*/*.cpp src/server/serverCommandLineInterface/*/*/*.cpp src/server/serverCommandLineInterface/*.cpp src/classifier/*.cpp src/classifier/*/*.cpp)
add_executable(testClient ${testClient_src} test/testClient/TestClient.cpp test/testClient/main.cpp)
file(GLOB testServer_src src/server/IOS/*.cpp src/server/client/*/*/*.cpp src/server/client/*/*/*/*.cpp src/server/client/*/*.cpp src/server/client/ClientCLI.cpp src/server/client/ClientIO.cpp)
add_executable(testServer ${testServer_src} test/testServer/main.cpp)

add_executable(testCsv test/csvTest/main.cpp src/server/IOS/CsvFileIO.cpp)