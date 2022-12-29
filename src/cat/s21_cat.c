#include "s21_cat.h"

int main(int argc, char **argv) {
    struct arg_keys args = {0};
    s21_cat_parcer(argc, argv, &args);
    s21_cat_output(argc, argv, &args);
    return 0;
}

void s21_cat_parcer(int argc, char **argv, struct arg_keys *args) {
    int count_args = 1;
    while (argc > count_args && args->key_error == 0) {
        if ((argv[count_args][0] == '-') && (argv[count_args][1] != '\0')) {
            for (int i = 1; i < (int)strlen(argv[count_args]); i++) {
                if (!strcmp(argv[count_args], "--number-nonblank")) {
                    memset(argv[count_args], '\0', strlen(argv[count_args]));
                    strcat(argv[count_args], "-b");
                }
                if (!strcmp(argv[count_args], "--number")) {
                    memset(argv[count_args], '\0', strlen(argv[count_args]));
                    strcat(argv[count_args], "-n");
                }
                if (!strcmp(argv[count_args], "--squeeze-blank")) {
                    memset(argv[count_args], '\0', strlen(argv[count_args]));
                    strcat(argv[count_args], "-s");
                }
                switch (argv[count_args][i]) {
                    case 'b':
                        args->key_n = 0;
                        args->key_b = 1;
                        break;
                    case 'e':
                        args->key_e = 1;
                        args->key_v = 1;
                        break;
                    case 'n':
                        if (args->key_b == 1) {
                            args->key_n = 0;
                        } else {
                            args->key_n = 1;
                        }
                        break;
                    case 's':
                        args->key_s = 1;
                        break;
                    case 't':
                        args->key_t = 1;
                        args->key_v = 1;
                        break;
                    case 'v':
                        args->key_v = 1;
                        break;
                    default:
                        args->key_error = 1;
                        break;
                }
            }
            memset(argv[count_args], '\0', strlen(argv[count_args]));
        }
        count_args++;
    }
}

void s21_cat_output(int argc, char **argv, struct arg_keys *args) {
    int lastSym = '\n';
    int currSym = '\n';
    int flagEnter = 1;
    int count_all_line = 1;
    int count_full_line = 1;
    if (args->key_error == 1) {
        printf("Неверно указаны ключи в аргументах командной строки!\n");
    } else {
        for (int i = 1; i < argc; i++) {
            if (argv[i][0] != '\0') {
                FILE *file;
                file = fopen(argv[i], "r");
                if (file == NULL) {
                    printf("%s: Нет такого файла или каталога.\n", argv[i]);
                    break;
                } else {
                    while (1) {
                        currSym = fgetc(file);
                        if (currSym == EOF) {
                            if (feof(file) != 0) {
                                break;
                            } else {
                                break;
                            }
                        } else {
                            if (args->key_s == 1) {
                                if (currSym != '\n') {
                                    flagEnter = 0;
                                } else if (currSym == '\n') {
                                    flagEnter++;
                                }
                                if (flagEnter > 2) {
                                    flagEnter--;
                                    lastSym = currSym;
                                    continue;
                                }
                            }
                            if (args->key_n == 1) {
                                if (lastSym == '\n') {
                                    printf("%6d\t", count_all_line);
                                    count_all_line++;
                                }
                            }
                            if (args->key_b == 1) {
                                if ((currSym != '\n') && (lastSym == '\n')) {
                                    printf("%6d\t", count_full_line);
                                    count_full_line++;
                                }
                            }
                            if (args->key_e == 1) {
                                if (currSym == '\n') {
                                    printf("$");
                                }
                            }
                            if (args->key_t == 1) {
                                if (currSym == '\t') {
                                    printf("^");
                                    currSym = 'I';
                                }
                            }
                            if (args->key_v == 1) {
                                if (currSym >= 0 && currSym <= 31 && currSym != '\t' && currSym != '\n') {
                                    printf("^%c", currSym + 64);
                                } else if (currSym == 127) {
                                    printf("^?");
                                } else if (args->key_t == 1 && currSym == '\t') {
                                    continue;
                                } else {
                                    printf("%c", currSym);
                                }
                            } else {
                                printf("%c", currSym);
                            }
                        }
                        lastSym = currSym;
                    }
                }
                fclose(file);
            }
        }
    }
}
