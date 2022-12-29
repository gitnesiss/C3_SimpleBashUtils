#ifndef SRC_GREP_S21_GREP_H_
#define SRC_GREP_S21_GREP_H_

#include <getopt.h>
#include <regex.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

struct arg_keys {
    int key_e;
    char patternE[1024];
    int key_i;
    int key_v;
    int key_c;
    int key_l;
    int key_n;
    int key_h;
    int key_s;
    int key_f;
    char patternF[1024];
    int key_o;
    int key_error;
    int key_error_value;
};

int s21_grep_parcer(int argc, char **argv, struct arg_keys *args);
void s21_grep_output(int argc, char **argv, struct arg_keys);
void s21_print_str(FILE *, regex_t *, struct arg_keys, int, char *, int);
int s21_regex(regex_t *, char *, struct arg_keys);
void s21_flag_v(int *, struct arg_keys);
int s21_flag_i(struct arg_keys);
void s21_file_open_regex(regex_t *regex, struct arg_keys , int *flag_file_err, int flag_registr, int flag_o);

#endif  /* SRC_GREP_S21_GREP_H_ */
