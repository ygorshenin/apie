#include <errno.h>
#include <stdlib.h>
#include <unistd.h>

#include "base/logging.h"

#define BUFSIZE 4096

int main() {
  char buffer[BUFSIZE];
  ssize_t bytes_read = 0;
  do {
    bytes_read = read(STDIN_FILENO, buffer, BUFSIZE);
    if (bytes_read < 0) {
      if (errno != EINTR)
        err_sys("Failed to read from stdin");
      continue;
    }
    if (write(STDOUT_FILENO, buffer, (size_t) bytes_read) < 0)
      err_sys("Failed to write to stdout");
  } while (bytes_read != 0);
  exit(0);
}
