cmake_minimum_required(VERSION 3.25.1)

project(comet-lang)

add_definitions(-DARGV="${ARGV}")

include_directories(../../src/win/util ../../src/win/lexer ../../src/win/parser ../../src/win/compiler)

add_executable(main
  ../../src/win/lexer/token.c
  ../../src/win/compiler/comet.c
  ../../src/win/parser/scanner.c
  ../../src/win/util/vector.c
  ../../src/win/util/string_util.c
  ../../src/win/util/hashmap.c)
