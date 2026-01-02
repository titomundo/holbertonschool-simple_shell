#ifndef SIMPLE_SHELL
#define SIMPLE_SHELL

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

void print_array(char **arr, int size);
void print_array2(char **arr);
int word_count(char *str);
int word_count2(char *str);
char **arg_array(char *str);
char **env_array(char *str);
void free_array(char **arr, int size);
void print_prompt(void);

#endif
