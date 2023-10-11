#include <stdlib.h>
#include <string.h>

#include "string_util.h"

char *substr(int start, int current, char *source) {
  int length = current - start;
  char *result = (char *)malloc(length + 1);

  if (result == NULL) {
    return NULL; // Memory allocation error
  }

  strncpy(result, source + start, length);
  result[length] = '\0'; // Null-terminate the string

  return result;
}
