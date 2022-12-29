CC=gcc
FLAGS=-Wall -Wextra -Werror -std=c11
NAME_FILE_OUT=-o s21_cat
NAME_FILE_IN=s21_cat.c
GOAL=

all: clean s21_cat

s21_cat:
	$(CC) -Wall -Wextra -std=c11 $(NAME_FILE_OUT) $(NAME_FILE_IN)

s21_grep:

test:

clean:
	rm -f *.out testFile/*.out *.o *.a *.css *.html *.gcda *.gcno *.gcov s21_cat

linter:


fout: clean
	$(CC) -Wall -Wextra -std=c11 $(NAME_FILE_OUT) $(NAME_FILE_IN)
	cat -e -s -t -v testFile/test_file.txt

foutF0TF0: clean
	$(CC) -Wall -Wextra -std=c11 $(NAME_FILE_OUT) $(NAME_FILE_IN)
	./s21_cat

foutF0TF1: clean
	$(CC) -Wall -Wextra -std=c11 $(NAME_FILE_OUT) $(NAME_FILE_IN)
	./s21_cat testFile/test1.txt

foutF0TF2: clean
	$(CC) -Wall -Wextra -std=c11 $(NAME_FILE_OUT) $(NAME_FILE_IN)
	./s21_cat testFile/test1.txt testFile/test2.txt

foutF1TF0: clean
	$(CC) -Wall -Wextra -std=c11 $(NAME_FILE_OUT) $(NAME_FILE_IN)
	./s21_cat -b -e -v

foutF1TF1: clean
	$(CC) -Wall -Wextra -std=c11 $(NAME_FILE_OUT) $(NAME_FILE_IN)
	./s21_cat -e -s -t -v testFile/test_file.txt

foutF1TF2: clean
	$(CC) -Wall -Wextra -std=c11 $(NAME_FILE_OUT) $(NAME_FILE_IN)
	./s21_cat -b -e -v testFile/test1.txt testFile/test2.txt

foutE: clean
	$(CC) -Wall -Wextra -std=c11 $(NAME_FILE_OUT) $(NAME_FILE_IN)
	./s21_cat  -e -t -v One Two Three Four

foutF: clean
	$(CC) -Wall -Wextra -std=c11 $(NAME_FILE_OUT) $(NAME_FILE_IN)
	./s21_cat  --squeeze-blank testFile/testF.txt

foutC: clean
	$(CC) -Werror -Wall -Wextra -std=c11 -o main.out main.c
	./main.out


createTestFileForCAT:
	$(CC) -Wall -Wextra -Werror -std=c11 -o testFile/createTestFileForCAT.out testFile/createTestFile.c
	./testFile/createTestFileForCAT.out

##########
point26:
	$(CC) $(FLAGS) -o point26.o point26main.c
	./point26.o

##########
point27:
	$(CC) $(FLAGS) -o point27.o pointAriph27main.c
	./point27.o

##########
point28:
	$(CC) $(FLAGS) -o student.o -c pointStruct28student.c
	$(CC) $(FLAGS) -o main.o -c pointStruct28main.c
	$(CC) $(FLAGS) -o point28.out student.o main.o
	./point28.out

##########
point29:
	$(CC) $(FLAGS) -o main.o -c pointFunc29main.c
	$(CC) $(FLAGS) -o arith.o -c pointFunc29arith.c
	$(CC) $(FLAGS) -o student.o -c pointFunc29student.c
	$(CC) $(FLAGS) -o point29.out main.o arith.o student.o
	./point29.out

##########
point33:
	$(CC) $(FLAGS) -o main.o -c argCMD33main.c
	$(CC) $(FLAGS) -o point33.out main.o
	./point33.out  -a 12

##########
argmain1: clean
	$(CC) -Wall -Wextra -Werror -std=c11 argMainGetOptLong.c
	./a.out --authornameshouldbeprinted --authornameshouldbeprinted --brackets -l

argmain2: clean
	$(CC) -Wall -Wextra -Werror -std=c11 argMainGetOptLong.c
	./a.out -l36 -a
	