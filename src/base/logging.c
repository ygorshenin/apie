#include "base/logging.h"

#include <errno.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void err_sys(const char* fmt, ...) {
  va_list args;
  va_start(args, fmt);
  vfprintf(stderr, fmt, args);
  va_end(args);
  fprintf(stderr, ": %s\n", strerror(errno));
  exit(-1);
}
