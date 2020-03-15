#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

int _printf(const char *format, ...);
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
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *_cstrdup(const char *);

/* Functions inside buffer_functions.c */
void save_to_buffer(char *buffer, char *f_text);

/* char *(*num_func(char type, char len))(int {the va_arg num), char len);*/
/* char *(*str_func(char))(char *{the va arg string}) */
/*
 * char *apply_precision(char *str);
 * char *apply_width(char *str);
 * char *apply_flags(char *str);
 */

void *_itoa(long int number, char length);
void *_itoba(long int number, char length);
/*
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
