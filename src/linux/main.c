#include <stdio.h>
#include <string.h>

#include "compiler/comet.h"

int main(int argc, char *argv[]) {
  char *arg = ARGV;
  if (ARGV != NULL && strstr(ARGV, ".cml") != NULL) {
    run_file(ARGV);
  } else {
    printf("%s", ARGV);
    run_prompt();
  }
}
