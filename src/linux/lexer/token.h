#pragma once

#include "../compiler/comet.h"

typedef enum {

  // Single character tokens
  LEFT_PAREN,
  RIGHT_PAREN,
  LEFT_BRACKET,
  RIGHT_BRACKET,
  LEFT_BRACE,
  RIGHT_BRACE,
  LEFT_ANGLE,
  RIGHT_ANGLE,
  PIPE,
  BANG,
  ASSIGN,
  COMMA,
  DOT,
  TACK,
  PLUS,
  SEMICOLON,
  FORWARD_SLASH,
  ASTERISK,
  BACKWARD_SLASH,
  AMPERSAND,
  GREATER,
  LESSER,
  QUESTION_MARK,
  UNDERSCORE,
  COLON,
  BIT_OR,
  BIT_AND,

  // Comparisons
  BANG_EQUAL,
  EQUAL,
  GREATER_EQUAL,
  LESSER_EQUAL,
  DOUBLE_PIPE,
  DOUBLE_AMP,

  // Literals
  IDENTIFIER,
  STRING,
  CHAR,
  NUM,
  IDENT,

  // Keywords
  IF,
  FOR,
  ELSE,
  FN,
  RETURN,
  THIS,
  WHILE,
  TRUE,
  FALSE,
  MATCH,
  STRUCT,
  ENUM,
  MOD,

  ENOF,

} TokenType;

typedef struct {

  TokenType type;
  char *lexeme;
  char literal;
  int line_num;

} Token;

const char *get_token_type(TokenType token);

void error(int line_num, char *message, Comet *comet);

void report(int line_num, char *where, char *message, Comet *comet);
