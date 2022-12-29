#include <stdio.h>
#include <string.h>

#define FILE_S21_TEST1 "result_S21CAT_test-b-n-s.txt"
#define FILE_CAT_TEST1 "result_CAT_test-b-n-s.txt"
#define FILE_S21_TEST2 "result_S21CAT_test-e-t-n-v.txt"
#define FILE_CAT_TEST2 "result_CAT_test-e-t-n-v.txt"

int main() {
    int countLine = 0;
    int test_failed = 0;
    int test_success = 0;
    char str_cat[100];
    char str_s21[100];
    FILE *file_cat_t1, *file_s21_t1, *file_cat_t2, *file_s21_t2;
    if ((file_cat_t1 = fopen(FILE_CAT_TEST1, "r")) == NULL) {
        printf("Файл открываемый CAT - пустой.\n");
        getchar();
        return 0;
    }
    if ((file_s21_t1 = fopen(FILE_S21_TEST1, "r")) == NULL) {
        printf("Файл открываемый S21 - пустой.\n");
        getchar();
        return 0;
    }
    while (fgets(str_cat, 100, file_cat_t1) != NULL && fgets(str_s21, 100, file_s21_t1) != NULL) {
        countLine++;
        printf("Сравниваются строки %3d \ncat- %ss21- %s", countLine, str_cat, str_s21);
        if (strcmp(str_cat, str_s21) == 0) {
            printf("+++++ %d строки идентичны. +++++\n", countLine);
            test_success++;
        } else {
            printf("----- %d строки различны. -----\n", countLine);
            test_failed++;
        }
    }
    fclose(file_cat_t1);
    fclose(file_s21_t1);
    printf("\n\n---------- --------- ----------\n");
    printf("Количество тестов: %3d.\n", countLine);
    printf("Тест пройден: %3d.\n", test_success);
    printf("Тест провален: %3d.\n", test_failed);

    printf("\n\n");
    if ((file_cat_t2 = fopen(FILE_CAT_TEST2, "r")) == NULL) {
        printf("Файл открываемый CAT - пустой.\n");
        getchar();
        return 0;
    }
    if ((file_s21_t2 = fopen(FILE_S21_TEST2, "r")) == NULL) {
        printf("Файл открываемый S21 - пустой.\n");
        getchar();
        return 0;
    }
    while (fgets(str_cat, 100, file_cat_t2) != NULL && fgets(str_s21, 100, file_s21_t2) != NULL) {
        countLine++;
        printf("Сравниваются строки %3d \ncat- %ss21- %s", countLine, str_cat, str_s21);
        if (strcmp(str_cat, str_s21) == 0) {
            printf("+++++ %d строки идентичны. +++++\n", countLine);
            test_success++;
        } else {
            printf("----- %d строки различны. -----\n", countLine);
            test_failed++;
        }
    }
    fclose(file_cat_t2);
    fclose(file_s21_t2);
    printf("\n\n---------- --------- ----------\n");
    printf("Количество тестов: %3d.\n", countLine);
    printf("Тест пройден: %3d.\n", test_success);
    printf("Тест провален: %3d.\n", test_failed);
}
