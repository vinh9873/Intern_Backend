cmake_minimum_required(VERSION 3.15)
project(file_service)

set(CMAKE_CXX_STANDARD 17)

find_package(oatpp CONFIG REQUIRED)

add_executable(file-service
    src/main.cpp
)

target_link_libraries(file-service
    PRIVATE oatpp::oatpp
)