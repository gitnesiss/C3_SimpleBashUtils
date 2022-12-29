CC=gcc
FLAGS=-Wall -Wextra -Werror -std=c11
NAME_FILE_IN=s21_grep.c
GOAL=-o s21_grep

all: clean s21_grep

s21_grep:
	$(CC) -Werror -Wall -Wextra -std=c11 $(GOAL) $(NAME_FILE_IN)

s21_grep_pattern:
	$(CC) -Werror -Wall -Wextra -std=c11 $(GOAL) $(NAME_FILE_IN)
	./s21_grep goo ../testFile/grep_test1.txt
	grep goo ../testFile/grep_test1.txt

s21_grep_e:
	$(CC) -Werror -Wall -Wextra -std=c11 $(GOAL) $(NAME_FILE_IN)
	./s21_grep -e goo -e yan ../testFile/grep_test1.txt
	grep -e goo -e yan ../testFile/grep_test1.txt

s21_grep_i:
	$(CC) -Werror -Wall -Wextra -std=c11 $(GOAL) $(NAME_FILE_IN)
	./s21_grep -in goo ../testFile/grep_test1.txt
	grep -in goo ../testFile/grep_test1.txt

s21_grep_v:
	$(CC) -Werror -Wall -Wextra -std=c11 $(GOAL) $(NAME_FILE_IN)
	./s21_grep -inv -e goo -e ya -e ir -e te -e e ../testFile/grep_test1.txt
	grep -inv -e goo -e ya -e ir -e te -e e ../testFile/grep_test1.txt

s21_grep_c:
	$(CC) -Werror -Wall -Wextra -std=c11 $(GOAL) $(NAME_FILE_IN)
	./s21_grep -inc goo ../testFile/grep_test1.txt
	grep -inc goo ../testFile/grep_test1.txt

s21_grep_l:
	$(CC) -Werror -Wall -Wextra -std=c11 $(GOAL) $(NAME_FILE_IN)
	./s21_grep -inl goo ../testFile/grep_test1.txt
	grep -inl goo ../testFile/grep_test1.txt
	
s21_grep_n:
	$(CC) -Werror -Wall -Wextra -std=c11 $(GOAL) $(NAME_FILE_IN)
	./s21_grep -n goo ../testFile/grep_test1.txt
	grep -n goo ../testFile/grep_test1.txt

s21_grep_h:
	$(CC) -Werror -Wall -Wextra -std=c11 $(GOAL) $(NAME_FILE_IN)
	./s21_grep -n -h goo ../testFile/grep_test1.txt ../testFile/grep_test2.txt
	grep -n -h goo ../testFile/grep_test1.txt ../testFile/grep_test2.txt

s21_grep_s_err:
	$(CC) -Werror -Wall -Wextra -std=c11 $(GOAL) $(NAME_FILE_IN)
	./s21_grep goo ../testFile/grep_test.txt
	grep goo ../testFile/grep_test.txt
s21_grep_s_noerr:
	./s21_grep -s goo ../testFile/grep_test.txt
	grep -s goo ../testFile/grep_test.txt

s21_grep_f:
	$(CC) -Werror -Wall -Wextra -std=c11 $(GOAL) $(NAME_FILE_IN)
	./s21_grep -f ../testFile/patterns_for_test.txt ../testFile/grep_test1.txt
	grep -f ../testFile/patterns_for_test.txt ../testFile/grep_test1.txt

s21_grep_of:
	$(CC) -Werror -Wall -Wextra -std=c11 $(GOAL) $(NAME_FILE_IN)
	./s21_grep -f ../testFile/patterns_for_test.txt ../testFile/grep_test1.txt
	grep -o -f ../testFile/patterns_for_test.txt ../testFile/grep_test1.txt

s21_grep_oni:
	$(CC) -Werror -Wall -Wextra -std=c11 $(GOAL) $(NAME_FILE_IN)
	./s21_grep -oni -e ceo -f ../testFile/patterns_for_test.txt ../testFile/grep_test1.txt
	grep -oni -e ceo -f ../testFile/patterns_for_test.txt ../testFile/grep_test1.txt

test:
	sh test_grep.sh

clean:
	rm -f s21_grep *.txt *.out

style:
	python3 cpplint.py --extensions=c *.c
	python3 cpplint.py --extensions=c *.h

leaks:
	leaks -atExit -- ./s21_cat | grep LEAK:
