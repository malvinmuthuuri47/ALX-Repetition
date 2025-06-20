#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

int _putchar(char c);
char *create_array(unsigned int size, char c);
char *_strdup(char *str);
char *str_concat(char *s1, char *s2);
int **alloc_grid(int width, int height);
void free_grid(int **grid, int height);
char *argstostr(int ac, char **av);
char **strtow(char *str);

/* my custom implementations */
size_t my_strlen(const char *s);
char *argstostr(int ac, char **av);
void copy_args_to_result(int ac, char **av, char *result);
int calculate_total_len(int ac, char **av);
int str_len(char *str);
char *copy_word(char *str, int start, int length);
int word_count(char *str);
int str_len(char *str);
int is_space(char c);

#endif
