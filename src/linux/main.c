#include <stdio.h>
#include <string.h>

#include "compiler/comet.h"

int main(int argc, char *argv[]) {
  char *arg = ARGV;
  if (arg != NULL && strstr(arg, ".cml") != NULL) {
    run_file(arg);
  } else {
    printf("%s", arg);
    run_prompt();
  }
}
