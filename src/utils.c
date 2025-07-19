#include "utils.h"
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool read_integer(const char *prompt, int *out) {
  char input[128];
  char *endptr;

  printf("%s", prompt);

  if (!fgets(input, sizeof(input), stdin)) return false;
  input[strcspn(input, "\n")] = 0;

  errno = 0;
  long result = strtol(input, &endptr, 10);

  if (errno == ERANGE || result < INT_MIN || result > INT_MAX) return false;
  if (endptr == input) return false;

  while (isspace((unsigned char)*endptr)) endptr++;
  if (*endptr != '\0') return false;

  *out = (int)result;
  return true;
}


bool read_float(const char *prompt, float *out) {
  char input[128];
  char *endptr;

  printf("%s", prompt);

  if (!fgets(input, sizeof(input), stdin)) return false;
  input[strcspn(input, "\n")] = 0;

  errno = 0;
  float result = strtof(input, &endptr);

  if (errno == ERANGE) return false;
  if (endptr == input) return false;

  while (isspace((unsigned char)*endptr)) endptr++;
  if (*endptr != '\0') return false;

  *out = result;
  return true;
}

bool read_string(const char *prompt, char *buffer, const size_t buffer_size) {
  if (!prompt || !buffer || buffer_size == 0) return false;

  printf("%s", prompt);

  if (!fgets(buffer, (int)buffer_size, stdin)) return false;

  // Remove newline if present
  buffer[strcspn(buffer, "\n")] = '\0';

  return true;
}
