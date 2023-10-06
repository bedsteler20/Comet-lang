#include "string_util.h"

char *substr(int start, int length, char *source) {

  int current_char = 0;
  char substring[sizeof(source)];

  while (current_char < length) {
    substring[current_char] = source[start + current_char - 1];
    current_char;
  }

  substring[current_char] = '\0';
  return substring;
}
