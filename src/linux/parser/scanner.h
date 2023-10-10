#pragma once

#include "../lexer/token.h"
#include "../util/vector.h"

typedef struct {
  char **key;
  TokenType *value;
} Keyword;

typedef struct {
  char *source;
  Token *token_list;
  Keyword *keywords;
  int start;
  int current;
  int line_num;
} Scanner;

TokenType *get_key(Keyword *keywords, char *key_want);

void init_keywords(Keyword *keywords);

void push_keywords(Keyword *keywords, char *key, TokenType value);

void identifier(Scanner *scanner);

bool token_is_alpha(char current_char);

bool token_is_alpha_num(char current_char);

bool token_is_digit(char current_char);

void number(Scanner *scanner);

void string(Scanner *scanner);

char peek(Scanner *scanner);

char peek_next(Scanner *scanner);

bool match(char *next, Scanner *scanner);

void add_token_to_vector(TokenType, char literal, char *lexeme, Scanner *scaner,
                         int line_num);

void add_token(TokenType type, Scanner *scanner);

void _add_token(TokenType type, char literal, Scanner *scanner);

void parse_tokens(Scanner *scanner);

void scan_token(Scanner *scanner);

char iter(Scanner *scanner);

bool end_of_source(Scanner *scanner);
