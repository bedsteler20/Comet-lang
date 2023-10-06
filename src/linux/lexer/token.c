#include <stdio.h>

#include "../compiler/comet.h"
#include "token.h"

void report(int line_num, char *where, char *message, Comet *comet) {
  printf("[line %d ] Error %s: %s", line_num, where, message);
  comet->had_error = true;
}

void error(int line_num, char *message, Comet *comet) {
  report(line_num, "", message, comet);
}
