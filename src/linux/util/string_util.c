#include <stdlib.h>
#include <string.h>

#include "string_util.h"

char *substr(int start, int length, char *source) {
  if (source == NULL || start < 0 || length < 0) {
    return NULL;
  }

  int source_length = strlen(source);

  if (start >= source_length || length == 0) {
    return NULL;
  }

  length = (start + length <= source_length) ? length : (source_length - start);

  char *substring = (char *)malloc(length + 1);

  if (substring == NULL) {
    return NULL;
  }

  strncpy(substring, source + start, length);
  substring[length] = '\0';

  return substring;
}
