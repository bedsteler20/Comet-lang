#include <stdio.h>
#include <string.h>

#include "../lexer/token.h"
#include "../parser/scanner.h"
#include "../util/vector.h"
#include "comet.h"

#define INPUT_LIMIT 100

char *read_file(char *file_path) {

  FILE *file;
  char *file_content;
  long byte_amount;

  file = fopen(file_path, "r");

  if (file == NULL)
    return NULL;

  fseek(file, 0L, SEEK_END);
  byte_amount = ftell(file);

  fseek(file, 0L, SEEK_SET);

  file_content = (char *)calloc(byte_amount, sizeof(char));

  if (file_content == NULL)
    return NULL;

  fread(file_content, sizeof(char), byte_amount, file);
  fclose(file);

  return file_content;
}

void run(char *source) {

  Scanner scanner = (Scanner){
      .source = source,
      .token_list = vector_create(),
      .start = 0,
      .current = 0,
      .keywords = &(Keyword){.key = NULL, .value = 0},
      .line_num = 0,
  };

  Scanner *p_scanner = &scanner;

  printf("SOURCE: %s\n", source);

  parse_tokens(p_scanner);

  Token *p_tokens = scanner.token_list;

  for (int i = 0; i < sizeof(*p_tokens) / sizeof(p_tokens[i]); i++) {
    printf("Token Name: %s\n", p_tokens[i].lexeme);
    printf("Token Type: %s\n", get_token_type(p_tokens[i].type));
    printf("Line Number: %d\n", p_tokens[i].line_num);
  }

  vector_free(p_tokens);
}

void run_prompt() {

  Comet comet;
  comet.had_error = false;

  char line[INPUT_LIMIT];
  while (1) {

    printf("> ");
    fgets(line, INPUT_LIMIT, stdin);

    if (strstr(line, "exit"))
      break;

    run(line);
    comet.had_error = false;
  }
}

void run_file(char *file_path) {
  char *file_content = read_file(file_path);
  run(file_content);
}
