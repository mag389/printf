#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

/* atoi */

/* Functions inside get_functions.c */
char *get_flags(char **fmt);
int get_width(char **fmt);
int get_prec(char **fmt);
char get_len(char **fmt);
char get_type(char **fmt);

/* Functions inside string_functions.c */
int _strlen(char *);
char *_strdup(char *);
void *_calloc(unsigned int nmemb, unsigned int size, char c);
/* space for _realloc */
/* space for a fifth function */

/* char *(*num_func(char type, char len))(int {the va_arg num), char len);*/
/* char *(*str_func(char))(char *{the va arg string}) */
/*
 * char *apply_precision(char *str);
 * char *apply_width(char *str);
 * char *apply_flags(char *str);
 */
/*
itoa(int i)
itod
itou..o..x..X..b
*/
/*
stoa()
Stoa()
rtoa()
Rtoa()
ctoa()
*/


#endif
