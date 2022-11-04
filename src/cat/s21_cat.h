#ifndef SRC_CAT_S21_CAT_H
#define SRC_CAT_S21_CAT_H

#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct flags {
  int b;
  int e;
  int n;
  int s;
  int t;
  int v;
} flags;

static struct option long_options[] = {{"number-nonblank", 0, 0, 'b'},
                                       {"number", 0, 0, 'n'},
                                       {"squeeze-blank", 0, 0, 's'},
                                       {0, 0, 0, 0}};

void check_flags(flags *short_flags, int argc, char **argv);
void reading(flags *short_flags, char **argv);

#endif  // SRC_CAT_S21_CAT_H
