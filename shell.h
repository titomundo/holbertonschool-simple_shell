#ifndef SIMPLE_SHELL
#define SIMPLE_SHELL

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>

/* AUX */
void print_prompt(void);
char *get_userin();

/* ARRAYS */
void print_array(char **arr);
int word_count(char *str);
int dir_count(char *path);
char **arg_array(char *str);
void free_array(char **arr);

/* PATH */
char *get_path(char **env);
char **split_path(char *path);
char *get_cmd(char **arr, char *cmd);

/* FORK */
int run_cmd(char *cmd, char **args, char **env, char *buf);

#endif
