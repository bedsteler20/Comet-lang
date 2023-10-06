#pragma once

#include <stdbool.h>
#include <stdio.h>

typedef struct {
  bool had_error;
} Comet;

void run_file(char *file_path);

char *read_file(char *file_path);

void run_prompt();

void run(char *source);
