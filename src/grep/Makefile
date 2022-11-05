CC = gcc
CFLAGS = -std=c11 -Wall -Werror -Wextra -g -D_GNU_SOURCE
OS := $(shell uname)

all: s21_grep
	
s21_grep:
	$(CC) $(CFLAGS) s21_grep.c -o s21_grep

test: rebuild
	chmod +x test_func_grep.sh
	chmod +x test_leak_grep.sh
	sh test_func_grep.sh
	sh test_leak_grep.sh

check: clean
	cp ../../materials/linters/.clang-format ../../src/.clang-format
	clang-format -n s21_grep.c s21_grep.h
	rm ../.clang-format
	make s21_grep
ifeq ($(OS), Darwin)
	leaks -atExit -- ./s21_grep
else ifeq ($(OS), Linux)
	CK_FORK=no valgrind --vgdb=no --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=RESULT_VALGRIND.txt ./s21_grep
endif

clean:
	rm -rf s21_grep s21_grep.dSYM s21_grep_test.txt grep_test.txt

rebuild: clean all