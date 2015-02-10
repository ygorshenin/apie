#include <dirent.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

#include "base/logging.h"

int main(int argc, const char** argv) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s dirs...\n", argv[0]);
    exit(-1);
  }

  for (const char** dirname = &argv[1]; *dirname; ++dirname) {
    DIR* dp = opendir(*dirname);
    struct dirent* entry;
    if (!dp)
      err_sys("Can't open directory %s", *dirname);

    /* Iterate through all entries in dp. */
    errno = 0;
    while ((entry = readdir(dp)) != NULL)
      puts(entry->d_name);
    if (errno < 0)
      err_sys("Can't read directory %s", *dirname);

    closedir(dp);
  }
  exit(0);
}
