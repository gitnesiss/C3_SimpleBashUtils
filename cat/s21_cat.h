#ifndef SRC_CAT_S21_CAT_H_
#define SRC_CAT_S21_CAT_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct arg_keys {
    int key_b;
    int key_e;
    int key_n;
    int key_s;
    int key_t;
    int key_v;
    int key_error;
};

void s21_cat_parcer(int argc, char **argv, struct arg_keys *args);
void s21_cat_output(int argc, char **argv, struct arg_keys *args);

#endif  // SRC_CAT_S21_CAT_H_
