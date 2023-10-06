#include <stdio.h>
#include <string.h>

#include "../lexer/token.h"
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

  char **tokens = vector_create();

  vector_add(&tokens, char*, source);

  for (int i = 0; i < vector_size(tokens); i++) {
    printf("%s\n", tokens[i]);
  }

  vector_free(tokens);
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
