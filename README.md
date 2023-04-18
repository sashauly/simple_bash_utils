# Simple Bash Utils
> 06.11.2022

## This is an educational project, so it's no longer supported!
***This is the project in which Bash text utilities(cat, grep) are implemented for working with C programming language texts. These utilities (cat and grep) are often used in the Linux terminal. As part of the project is to learn the organization of the Bash utilities and solidify knowledge of structured programming.***

## Important notes

> - The programs developed in C language of C11 standard using gcc compiler.
> - The program code of the cat and grep located in the src/cat/ and src/grep/ folders, respectively  
> - Written code follows the Google style (see `clang` goal in Makefile)
> - The programs are executable files with command line arguments
> - The programs built with Makefile with appropriate targets: `s21_cat`, `s21_grep`
> - Integration tests covered all flag variants and input values, based on a comparison with the behavior of real Bash utilities(see `test` goal in Makefile)
> - The programs developed according to the principles of structured programming

## Cat utility

- cat Usage `cat [OPTION] [FILE]...`

- cat Options
  - Support of all flags (including GNU versions) specified below

| No. | Options | Description |
| ------ | ------ | ------ |
| 1 | -b (GNU: --number-nonblank) | numbers only non-empty lines |
| 2 | -e implies -v (GNU only: -E the same, but without implying -v) | but also display end-of-line characters as $  |
| 3 | -n (GNU: --number) | number all output lines |
| 4 | -s (GNU: --squeeze-blank) | squeeze multiple adjacent blank lines |
| 5 | -t implies -v (GNU: -T the same, but without implying -v) | but also display tabs as ^I  |

## Grep utility
- grep Usage `grep [options] template [file_name]`

- grep Options
  - Support of all flags, including their _pair_ combinations (e.g. `-iv`, `-in`)

| No. | Options | Description |
| ------ | ------ | ------ |
| 1 | -e | pattern |
| 2 | -i | Ignore uppercase vs. lowercase.  |
| 3 | -v | Invert match. |
| 4 | -c | Output count of matching lines only. |
| 5 | -l | Output matching files only.  |
| 6 | -n | Precede each matching line with a line number. |
| 7 | -h | Output matching lines without preceding them by file names. |
| 8 | -s | Suppress error messages about nonexistent or unreadable files. |
| 9 | -f file | Take regexes from a file. |
| 10 | -o | Output the matched parts of a matching line. |
