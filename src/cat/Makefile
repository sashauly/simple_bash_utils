CC = gcc
CFLAGS = -std=c11 -Wall -Werror -Wextra -g
OS := $(shell uname)

all: s21_cat
	
s21_cat:
	$(CC) $(CFLAGS) s21_cat.c -o s21_cat

test: s21_cat
	chmod +x test_func_cat.sh
	chmod +x test_leak_cat.sh
	sh test_func_cat.sh
	sh test_leak_cat.sh

check:
	cp ../../materials/linters/.clang-format ../../src/.clang-format
	clang-format -n s21_cat.c s21_cat.h
	rm ../.clang-format
	make s21_cat
ifeq ($(OS), Darwin)
		leaks -atExit -- ./s21_cat
else ifeq ($(OS), Linux)
		CK_FORK=no valgrind --vgdb=no --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=RESULT_VALGRIND.txt ./s21_cat
endif


clean:
	rm -rf s21_cat s21_cat.dSYM s21_cat_test.txt cat_test.txt

rebuild: clean all