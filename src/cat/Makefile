CC=gcc
FLAGS=-Wall -Wextra -Werror -std=c11
NAME_FILE_IN=s21_cat.c
GOAL=-o s21_cat

all: clean s21_cat

s21_cat:
	$(CC) -Werror -Wall -Wextra -std=c11 $(GOAL) $(NAME_FILE_IN) 

test:
	./s21_cat -b -e -s -t -v ../testFile/test-b-n-s.txt > result_S21CAT_test-b-n-s.txt
	cat -b -e -s -t -v ../testFile/test-b-n-s.txt > result_CAT_test-b-n-s.txt
	./s21_cat -e -t -s -n -v ../testFile/test-e-t-n-v.txt > result_S21CAT_test-e-t-n-v.txt
	cat -e -t -s -n -v ../testFile/test-e-t-n-v.txt > result_CAT_test-e-t-n-v.txt
	$(CC) -Werror -Wall -Wextra -std=c11 -o test_text_file.out s21_cat_tests.c
	./test_text_file.out
	rm -f test_text_file.out
	rm -f result_S21CAT_test-b-n-s.txt result_CAT_test-b-n-s.txt
	rm -f result_S21CAT_test-e-t-n-v.txt result_CAT_test-e-t-n-v.txt

cASCII:
	$(CC) -Werror -Wall -Wextra -std=c11 -o createTestFile.out ../testFile/createTestFile.c
	./createTestFile.out
	rm -f createTestFile.out

clean:
	rm -f s21_cat *.txt

style:
	python3 cpplint.py --extensions=c *.c
	python3 cpplint.py --extensions=c *.h

leaks:
	leaks -atExit -- ./s21_cat | grep LEAK:
