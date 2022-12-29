#include "s21_grep.h"

int main(int argc, char **argv) {
    struct arg_keys args = {0};
    if (s21_grep_parcer(argc, argv, &args) == 0) {
        s21_grep_output(argc, argv, args);
    }
    return 0;
}

int s21_grep_parcer(int argc, char **argv, struct arg_keys *args) {
    if (argc > 1) {
        int rez;
        const char* optstring = "e:ivclnhsf:o";
        while ((rez = getopt(argc, argv, optstring)) != -1) {
            switch (rez) {
                case 'e':
                    if (!args->key_e) {
                        args->key_e = 1;
                        strcat(args->patternE, optarg);
                    } else {
                        strcat(args->patternE, "|\0");
                        strcat(args->patternE, optarg);
                    }
                    break;
                case 'i':
                    args->key_i = 1;
                    break;
                case 'v':
                    args->key_v = 1;
                    args->key_o = 0;
                    break;
                case 'c':
                    args->key_c = 1;
                    break;
                case 'l':
                    args->key_l = 1;
                    break;
                case 'n':
                    args->key_n = 1;
                    break;
                case 'h':
                    args->key_h = 1;
                    break;
                case 's':
                    args->key_s = 1;
                    break;
                case 'f':
                    args->key_f = 1;
                    strcat(args->patternF, optarg);
                    break;
                case 'o':
                    if (args->key_v == 0) {
                        args->key_o = 1;
                    }
                    break;
                default:
                    args->key_error = rez;
                    args->key_error_value = optopt;
                    break;
            }
        }
    } else {
        printf("Для работы с s21_grep использовать вызов вида: s21_grep [options] template [file_name].\n");
        args->key_error = 1;
    }
    return args->key_error;
}

void s21_grep_output(int argc, char **argv, struct arg_keys args) {
    int f_str = optind;
    FILE *fp = NULL;
    if (args.key_e == 0 && args.key_f == 0) {
        f_str++;
    }
    regex_t regex = {0};
    if (s21_regex(&regex, argv[optind], args) == 0) {
        for (int i = 0; (f_str + i) < argc; i++) {
            fp = fopen(argv[f_str + i], "r");
            if (fp == 0) {
                if (args.key_s == 0) {
                    printf("s21_grep: %s: No such file or directory\n", argv[f_str + i]);
                }
            } else {
                s21_print_str(fp, &regex, args, argc, argv[f_str + i], f_str);
            }
            fclose(fp);
        }
    }
    regfree(&regex);
}

int s21_regex(regex_t *regex, char *array, struct arg_keys args) {
    int flag_registr = s21_flag_i(args);
    int flag_file_err = 0;
    int flag_o = args.key_o ? 0 : REG_NOSUB;
    if (args.key_e && args.key_f) {
        s21_file_open_regex(regex, args, &flag_file_err, flag_registr, flag_o);
    } else if (args.key_e) {
        regcomp(regex, args.patternE, flag_registr | flag_o | REG_EXTENDED);
    } else if (args.key_f) {
        s21_file_open_regex(regex, args, &flag_file_err, flag_registr, flag_o);
    } else {
        regcomp(regex, array, flag_registr | flag_o | REG_EXTENDED);
    }
    return flag_file_err ? -1 : 0;
}

void s21_print_str(FILE *file, regex_t *r, struct arg_keys args, int num, char *arr, int f_str) {
    int count_n = 0;
    int count_c = 0;
    char buff[BUFSIZ] = {'\0'};
    char buff_o[BUFSIZ] = {'\0'};
    int flag_l_ok = 0;
    int flag_n_ok = 0;
    int flag_h_ok = 0;
    size_t nmatch = 1;
    regmatch_t pmatch[1] = {0};
    while (fgets(buff, 1024, file) != NULL && !args.key_error && !flag_l_ok) {
        count_n++;
        flag_n_ok = 0;
        flag_h_ok = 0;
        int success = regexec(r, buff, nmatch, pmatch, 0);
        s21_flag_v(&success, args);
        if (!success) {
            count_c++;
            do {
                if (args.key_l) {
                    flag_l_ok = 1;
                    break;
                }
                if (!args.key_c && !args.key_h && (num - f_str - 1) && !flag_h_ok) {
                    printf("%s:", arr);
                    flag_h_ok = 1;
                }
                if (!args.key_c && args.key_n && !flag_n_ok) {
                    printf("%d:", count_n);
                    flag_n_ok = 1;
                }
                if (!args.key_c && args.key_o) {
                    strncpy(buff_o, &buff[pmatch[0].rm_so], pmatch[0].rm_eo - pmatch[0].rm_so);
                    strcat(buff_o, "\n\0");
                    printf("%s", buff_o);
                    memset(buff_o, '\0', strlen(buff_o));
                }
                if (!args.key_c && !args.key_o) {
                    printf("%s", buff);
                    if (buff[strlen(buff) - 1] != '\n') {
                        printf("\n");
                    }
                }
                if (args.key_o) {
                    strcpy(buff_o, &buff[pmatch[0].rm_eo]);
                    success = regexec(r, buff_o, nmatch, pmatch, 0);
                    memset(buff, '\0', strlen(buff_o));
                    strcat(buff, buff_o);
                    memset(buff_o, '\0', strlen(buff_o));
                }
            } while (!success && args.key_o);
        }
        memset(buff, '\0', strlen(buff));
    }
    if (args.key_c) {
        if (!args.key_h && (num - f_str - 1)) {
            printf("%s:", arr);
        }
        printf("%d\n", count_c);
    }
    if (args.key_l && flag_l_ok) {
        printf("%s\n", arr);
    }
}

void s21_flag_v(int *sym, struct arg_keys args) {
    if (args.key_v && !args.key_o) {
        *sym = !*sym;
    }
}

int s21_flag_i(struct arg_keys args) {
    int s = 0;
    if (args.key_i) {
        s = REG_ICASE;
    }
    return s;
}

void s21_file_open_regex(regex_t *regex, struct arg_keys args, int *flag_file_err,
                                                    int flag_registr, int flag_o) {
    FILE *fp = fopen(args.patternF, "r");
    if (fp == 0) {
        if (args.key_s == 0) {
            printf("s21_grep: %s: No such file or directory\n", args.patternF);
            *flag_file_err = 1;
        }
    } else {
        char sym = '\0';
        char buf_str[2] = {'\0'};
        char f_buff[BUFSIZ] = {'\0'};
        while ((sym = getc(fp)) != EOF) {
            buf_str[0] = sym;
            if (buf_str[0] == '\n') {
                buf_str[0] = '|';
            }
            buf_str[1] = '\0';
            strcat(f_buff, buf_str);
        }
        if (args.key_e) {
            strcat(f_buff, "|");
            strcat(f_buff, args.patternE);
        }
        regcomp(regex, f_buff, flag_registr | flag_o | REG_EXTENDED);
    }
    fclose(fp);
}
