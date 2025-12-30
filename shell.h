#ifndef SIMPLE_SHELL
#define SIMPLE_SHELL

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_array(char **arr, int size);
int word_count(char *str);
char **arg_array(char *str);
void free_array(char **arr, int size);

#endif
