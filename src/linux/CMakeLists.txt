cmake_minimum_required(VERSION 3.25.1)

project(comet-lang)

add_definitions(-DARGV="${ARGV}")

include_directories(../../src/linux/util ../../src/linux/lexer
                    ../../src/linux/parser ../../src/linux/compiler)

add_executable(main main.c lexer/token.c compiler/comet.c parser/scanner.c
                    util/vector.c util/string_util.c)
