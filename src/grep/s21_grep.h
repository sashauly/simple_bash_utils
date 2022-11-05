#ifndef SRC_GREP_S21_GREP_H
#define SRC_GREP_S21_GREP_H

#include <getopt.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFF_SIZE 8192

typedef struct flags {
  int e; /* Шаблон */
  int i; /* Игнорирует различия регистра */
  int v; /* Инвертирует смысл поиска соответствий */
  int c; /* Выводит только количество совпадающих строк */
  int l; /* Выводит только совпадающие файлы */
  int n; /* Предваряет каждую строку вывода номером строки из файла ввода */
  int h; /* Выводит совпадающие строки, не предваряя их именами файлов */
  int s; /* Подавляет сообщения об ошибках о несуществующих или нечитаемых
            файлах */
  int f; /* Получает регулярные выражения из файла */
  int o; /* Печатает только совпадающие (непустые) части совпавшей строки */
} flags;

static struct option long_options[] = {
    {"e", 0, 0, 'e'}, {"i", 0, 0, 'i'}, {"v", 0, 0, 'v'}, {"c", 0, 0, 'c'},
    {"l", 0, 0, 'l'}, {"n", 0, 0, 'n'}, {"h", 0, 0, 'h'}, {"s", 0, 0, 's'},
    {"f", 0, 0, 'f'}, {"o", 0, 0, 'o'}, {0, 0, 0, 0}};

void check_flags(flags *short_flags, char *pattern, int argc, char **argv);
void read_file_pattern(int *e_count, char *pattern, char **argv);
void search_matches(flags *short_flags, char *pattern, int file_count,
                    char **argv);

#endif  // SRC_GREP_S21_GREP_H
