#include "s21_cat.h"

/*
 *  Функция проверки наличия и считывания флагов из командой строки
 */
void check_flags(flags *short_flags, int argc, char **argv) {
  int rez = 0;
  const char *short_options = "+bEnsTvet";
  while ((rez = getopt_long(argc, argv, short_options, long_options, NULL)) !=
         -1) {
    switch (rez) {
      case 'b':
        short_flags->b = 1;
        break;
      case 'E':
        short_flags->e = 1;
        break;
      case 'n':
        short_flags->n = 1;
        break;
      case 's':
        short_flags->s = 1;
        break;
      case 'T':
        short_flags->t = 1;
        break;
      case 'v':
        short_flags->v = 1;
        break;
      case 'e':
        short_flags->e = 1;
        short_flags->v = 1;
        break;
      case 't':
        short_flags->t = 1;
        short_flags->v = 1;
        break;
      case '?':
        fprintf(
            stderr,
            "s21_cat: illegal option %s\nusage: cat [-beEnstTv] [file ...]\n",
            argv[optind - 1]);
        break;
    }
    if (short_flags->b && short_flags->n) short_flags->n = 0;
  }
}

/*
 * Функция чтения файла с учетом переданных флагов
 */
void reading(flags *short_flags, char **argv) {
  FILE *fp = NULL;
  fp = fopen(argv[optind], "r");
  if (fp != NULL) {
    int line_count = 1;       /* Счётчик строк */
    int empty_line_count = 0; /* Счётчик пустых строк */
    char prev_c = '\n'; /* Проверка предыдущего символа на наличие знака
                            переноса строки */
    while (!feof(fp)) {
      int c = fgetc(fp);
      if (c == EOF) break;
      if (short_flags->s && c == '\n' && prev_c == '\n') {
        empty_line_count++;
        if (empty_line_count > 1) {
          continue;
        }
      } else {
        empty_line_count = 0;
      }
      if (prev_c == '\n' && ((short_flags->b && c != '\n') || short_flags->n))
        printf("%6d\t", line_count++);
      if (short_flags->t && c == '\t') {
        printf("^");
        c = 'I';
      }
      if (short_flags->e && c == '\n') printf("$");
      if (c != '\n' && short_flags->v) {
        if (c < 32 && c != 9 && c != 10) {
          printf("^");
          c += 64;
        } else if (c > 127 && c < 160) {
          printf("M-^");
          c -= 64;
        } else if (c == 127) {
          printf("^");
          c -= 64;
        }
      }
      printf("%c", c);
      prev_c = c;
    }
    fclose(fp);
  } else {
    fprintf(stderr, "s21_cat: %s: No such file or directory\n", argv[optind]);
  }
}

int main(int argc, char **argv) {
  flags short_flags = {0};
  check_flags(&short_flags, argc, argv);
  while (optind < argc) {
    reading(&short_flags, argv);
    optind++;
  }
  return 0;
}
