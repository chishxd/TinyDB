#ifndef UTILS_H
#define UTILS_H
#include <stdbool.h>
#include <stddef.h>

bool read_integer(const char *prompt, int *out);
bool read_float(const char *prompt, float *out);
bool read_string(const char *prompt, char *buffer, size_t buffer_size);

#endif //UTILS_H
