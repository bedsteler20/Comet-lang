#include <string.h>

#include "../util/string_util.h"
#include "../util/vector.h"
#include "scanner.h"

TokenType *get_key(Keyword *keywords, char *key_want) {

  int index;

  for (index = 0; index < sizeof(*keywords->key) / sizeof(keywords->key[index]);
       index++) {
    printf("INSIDE GET_KEY FOR LOOP\n");
    if (strcmp(*keywords->key, key_want) &&
        sizeof(keywords->key) == sizeof(keywords->value)) {
      return keywords[index].value;
    }
  }

  return NULL;
}

void init_keywords(Keyword *keywords) {
  keywords->key = vector_create();
  keywords->value = vector_create();

  if (keywords->key == NULL) {
    printf("KEYWORDS KEY VECTOR IS NULL\n");
  }

  if (keywords->value == NULL) {
    printf("KEYWORDS VALUE VECTOR IS NULL\n");
  }

  // Push keywords into the array
  push_keywords(keywords, "if", IF);
  push_keywords(keywords, "for", FOR);
  push_keywords(keywords, "else", ELSE);
  push_keywords(keywords, "fn", FN);
  push_keywords(keywords, "return", RETURN);
  push_keywords(keywords, "this", THIS);
  push_keywords(keywords, "while", WHILE);
  push_keywords(keywords, "true", TRUE);
  push_keywords(keywords, "false", FALSE);
  push_keywords(keywords, "match", MATCH);
  push_keywords(keywords, "struct", STRUCT);
  push_keywords(keywords, "enum", ENUM);
  push_keywords(keywords, "mod", MOD);
  push_keywords(keywords, "enof", ENOF);
}

void push_keywords(Keyword *keywords, char *key, TokenType value) {
  vector_add(&keywords->key, key);
  vector_add(&keywords->value, value);
}

char peek(Scanner *scanner) {

  if (end_of_source(scanner))
    return '\0';
  return scanner->source[scanner->current];
}

char peek_next(Scanner *scanner) {
  if (scanner->current + 1 >= sizeof(scanner->source))
    return '\0';

  return scanner->source[scanner->current + 1];
}

char iter(Scanner *scanner) { return scanner->source[scanner->current++]; }

void add_token(TokenType type, Scanner *scanner) {
  _add_token(type, NULL, scanner);
}

void _add_token(TokenType type, char literal, Scanner *scanner) {
  char *source = substr(scanner->start, scanner->current, scanner->source);
  add_token_to_vector(type, literal, source, scanner, scanner->line_num);
}

void add_token_to_vector(TokenType type, char literal, char *lexeme,
                         Scanner *scanner, int line_num) {

  printf("INSIDE ADD_TOKEN_TO_VECTOR\n");

  if (scanner->token_list != NULL) {

    vector_add(&scanner->token_list, ((Token){.type = type,
                                              .lexeme = lexeme,
                                              .literal = literal,
                                              .line_num = line_num}));
  } else {
    scanner->token_list = vector_create();

    vector_add(&scanner->token_list, ((Token){.type = type,
                                              .lexeme = lexeme,
                                              .literal = literal,
                                              .line_num = line_num}));
  }
}

void identifier(Scanner *scanner) {
  printf("INSIDE IDENTIFIER\n");

  while (token_is_alpha_num(peek(scanner)))
    iter(scanner);

  char *text = substr(scanner->start, scanner->current - scanner->start,
                      scanner->source);
  if (text == NULL) {
    printf("Memory allocation failed for identifier\n");
    exit(EXIT_FAILURE);
  }

  TokenType *token_type = get_key(scanner->keywords, text);

  if (token_type == NULL) {
    add_token(IDENT, scanner);
  } else {
    add_token(*token_type, scanner);
  }

  free(text);
}

bool token_is_alpha(char current_char) {
  return (current_char >= 'a' && current_char <= 'z') ||
         (current_char >= 'A' && current_char <= 'Z') || (current_char == '_');
}

bool token_is_digit(char current_char) {
  return current_char >= '0' && current_char <= '9';
}

bool token_is_alpha_num(char current_char) {
  return token_is_alpha(current_char) || token_is_digit(current_char);
}
void number(Scanner *scanner) {

  while (token_is_digit(peek(scanner)))
    iter(scanner);

  if (peek(scanner) == '.' && token_is_digit(peek_next(scanner))) {
    iter(scanner);

    while (token_is_digit(peek(scanner)))
      iter(scanner);
  }

  _add_token(NUM, *substr(scanner->start, scanner->current, scanner->source),
             scanner);
}

void string(Scanner *scanner) {

  while (peek(scanner) != '"' && !end_of_source(scanner)) {
    if (peek(scanner) == '\n')
      scanner->line_num++;
    iter(scanner);
  }

  if (end_of_source(scanner)) {
    error(scanner->line_num, "Unterminated String.",
          &((Comet){.had_error = true}));
    return;
  }

  iter(scanner);

  char *string_value =
      substr(scanner->start + 1, scanner->current - 1, scanner->source);
  _add_token(STRING, *string_value, scanner);
}

bool match(char *expected_token, Scanner *scanner) {

  if (end_of_source(scanner))
    return false;

  if (!strcmp(&scanner->source[scanner->current], expected_token))
    return false;

  scanner->current++;
  return true;
}

void scan_token(Scanner *scanner) {

  printf("INSIDE SCAN_TOKEN\n");

  char current_char = iter(scanner);
  switch (current_char) {
  case '(':
    add_token(LEFT_PAREN, scanner);
    break;
  case ')':
    add_token(RIGHT_PAREN, scanner);
    break;
  case '{':
    add_token(LEFT_BRACE, scanner);
    break;
  case '}':
    add_token(RIGHT_BRACE, scanner);
    break;
  case ',':
    add_token(COMMA, scanner);
    break;
  case '.':
    add_token(DOT, scanner);
    break;
  case '-':
    add_token(TACK, scanner);
    break;
  case '+':
    add_token(PLUS, scanner);
    break;
  case ';':
    add_token(SEMICOLON, scanner);
    break;
  case '*':
    add_token(ASTERISK, scanner);
    break;
  case '!':
    add_token(match("=", scanner) ? BANG_EQUAL : BANG, scanner);
    break;
  case '=':
    add_token(match("=", scanner) ? EQUAL : ASSIGN, scanner);
    break;
  case '<':
    add_token(match("=", scanner) ? LESSER_EQUAL : LESSER, scanner);
  case '>':
    add_token(match("=", scanner) ? GREATER_EQUAL : GREATER, scanner);
    break;
  case '/':
    if (match("/", scanner)) {
      while (peek(scanner) != '\n' && !end_of_source(scanner))
        iter(scanner);
    } else {
      add_token(FORWARD_SLASH, scanner);
    }
    break;
  case '&':
    if (match("&", scanner)) {
      add_token(DOUBLE_AMP, scanner);
    } else {
      add_token(AMPERSAND, scanner);
    }
    break;
  case '|':
    if (match("|", scanner)) {
      add_token(DOUBLE_PIPE, scanner);
    } else {
      add_token(PIPE, scanner);
    }
    break;
  case ' ':
    break;
  case '\r' | '\t':
    break;
  case '\n':
    scanner->line_num++;
    break;
  case '"':
    string(scanner);
    break;
  default:
    if (token_is_digit(current_char)) {
      number(scanner);
    } else if (token_is_alpha(current_char)) {
      identifier(scanner);
    } else {
      error(scanner->line_num, "Unexpected Token",
            (&(Comet){.had_error = true}));
    }
  }
}

bool end_of_source(Scanner *scanner) {
  return scanner->current >= sizeof(scanner->source);
}

void parse_tokens(Scanner *scanner) {

  printf("INSIDE PARSE_TOKENS!\n");

  init_keywords(scanner->keywords);

  while (!end_of_source(scanner)) {
    scanner->start = scanner->current;
    scan_token(scanner);
  }

  add_token_to_vector(ENOF, NULL, "", scanner, scanner->line_num);
}
