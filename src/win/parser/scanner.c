#include <string.h>

#include "../util/hashmap.h"
#include "../util/string_util.h"
#include "../util/vector.h"
#include "scanner.h"

void init_keywords(Hashmap *keywords) {
  hashmap_init(keywords, hashmap_hash_string_i, strcmp);

  push_keywords(keywords, (&(HashmapKey){.key = "struct"}), STRUCT);
  push_keywords(keywords, (&(HashmapKey){.key = "enum"}), ENUM);
  push_keywords(keywords, (&(HashmapKey){.key = "for"}), FOR);
  push_keywords(keywords, (&(HashmapKey){.key = "while"}), WHILE);
  push_keywords(keywords, (&(HashmapKey){.key = "if"}), IF);
  push_keywords(keywords, (&(HashmapKey){.key = "fn"}), FN);
  push_keywords(keywords, (&(HashmapKey){.key = "true"}), TRUE);
  push_keywords(keywords, (&(HashmapKey){.key = "false"}), FALSE);
  push_keywords(keywords, (&(HashmapKey){.key = "return"}), RETURN);
  push_keywords(keywords, (&(HashmapKey){.key = "match"}), MATCH);
  push_keywords(keywords, (&(HashmapKey){.key = "mod"}), MOD);
  push_keywords(keywords, (&(HashmapKey){.key = "this"}), THIS);
}

void push_keywords(Hashmap *keywords, HashmapKey *key, TokenType keyword) {
  hashmap_put(keywords, key->key, &keyword);
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

  if (scanner->token_list != NULL) {
    Token *tokens = vector_add_asg(&scanner->token_list);

    vector_add(&tokens, ((Token){.type = type,
                                 .lexeme = lexeme,
                                 .literal = literal,
                                 .line_num = line_num}));
  } else {
    scanner->token_list = vector_create();

    Token *tokens = vector_add_asg(&scanner->token_list);

    vector_add(&tokens, ((Token){.type = type,
                                 .lexeme = lexeme,
                                 .literal = literal,
                                 .line_num = line_num}));
  }
}

void identifier(Scanner *scanner) {

  while (token_is_alpha_num(peek(scanner)))
    iter(scanner);

  char *text = substr(scanner->start, scanner->current, scanner->source);
  TokenType *token_type = hashmap_get(scanner->keywords, text);

  if (*token_type == NULL)
    *token_type = IDENT;
  add_token(*token_type, scanner);

  add_token(IDENT, scanner);
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
      error(scanner->line_num, "Unexpected Token", scanner);
    }
  }
}

bool end_of_source(Scanner *scanner) {
  return scanner->current >= sizeof(scanner->source);
}

Token *parse_tokens(Scanner *scanner) {

  init_keywords(&scanner->keywords);

  while (!end_of_source(scanner)) {
    scanner->start = scanner->current;
    scan_token(scanner);
  }

  add_token_to_vector(ENOF, NULL, "", scanner, scanner->line_num);
  return scanner->token_list;
}
