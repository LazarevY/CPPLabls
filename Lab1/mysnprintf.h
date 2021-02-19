#ifndef MYSNPRINTF_H
#define MYSNPRINTF_H
#include <stddef.h>
#include <cstdarg>

int concat_str(char *dist, const char * src, int maxLen =-1);
int resize_string(char *old_ptr, char *new_ptr, int newSize);

int my_snprintf(char * s, size_t n, const char * format, ...);

#endif // MYSNPRINTF_H
