cmake_minimum_required(VERSION 3.25.1)

project(comet-lang)

add_definitions(-DARGV="${ARGV}")

include_directories(../../src/win/util ../../src/linux/lexer ../../src/linux/parser ../../src/linux/compiler)

add_executable(main
  ../../src/linux/lexer/token.c
  ../../src/linux/compiler/comet.c
  ../../src/linux/parser/scanner.c
  ../../src/linux/util/vector.c
  ../../src/linux/util/string_util.c
  ../../src/linux/util/hashmap.c)
