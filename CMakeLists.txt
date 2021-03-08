cmake_minimum_required(VERSION 3.5)
set(PROJECT_NAME test_cli)
project(${PROJECT_NAME} LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_executable(${PROJECT_NAME} 
CLI/App.hpp
CLI/CLI.hpp
CLI/Config.hpp
CLI/ConfigFwd.hpp
CLI/Error.hpp
CLI/Formatter.hpp
CLI/FormatterFwd.hpp
CLI/Macros.hpp
CLI/Option.hpp
CLI/Split.hpp
CLI/StringTools.hpp
CLI/Timer.hpp
CLI/TypeTools.hpp
CLI/Validators.hpp
CLI/Version.hpp
main.cpp
) 
