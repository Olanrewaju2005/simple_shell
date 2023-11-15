#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

int _printstr(char *text);
ssize_t _getline(char **lineptr, size_t *size);
void *_realloc(void *prev_alloc, ssize_t o_size, ssize_t n_size);
void update_line_size(char **lineptr, size_t *size, char *buffer, size_t bufsize);
char *_strtok(char *str, const char *delim);
int _str_len(char *str);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
char *get_location(char *arg);
char *arg_location(char *path, char *arg);
int _putchar(char c);
int handle_builtin(char *cmd, char *arg[]);
char *ss_getenv(const char *env_name);

#endif
