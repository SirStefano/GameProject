cmake_minimum_required(VERSION 3.22)

project(my_app)

set(SFML_STATIC_LIBRARIES TRUE)

find_package(SFML 2 COMPONENTS graphics audio REQUIRED PATHS ./libraries/SFML-2.6.0/lib/cmake/SFML)

set(SOURCE_FILES SourceFiles/Map.cpp SourceFiles/MainCharacter.cpp SourceFiles/UI.cpp SourceFiles/NPC.cpp)

add_executable(my_app main.cpp ${SOURCE_FILES})

target_link_libraries(my_app sfml-graphics sfml-audio)

target_include_directories(my_app PUBLIC ./libraries/SFML-2.6.0/include/SFML)
target_include_directories(my_app PUBLIC ./HeadersFiles)