cmake_minimum_required(VERSION 3.20)
project(Database)

set(CMAKE_CXX_STANDARD 17)

add_executable(Database main.cpp token.cpp token.h condition_parser.cpp condition_parser.h database.cpp database.h date.cpp date.h node.cpp node.h test_runner.h condition_parser_test.h)
