#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int _printf(const char *format, ...);
/* atoi */

/* Functions inside get_functions.c */
char *get_flags(char **fmt);
int get_width(char **fmt);
int get_prec(char **fmt, va_list args);
char get_len(char **fmt);
char get_type(char **fmt);

/* Functions inside string_functions.c */
int _strlen(char *);
char *_strdup(char *);
void *_calloc(unsigned int nmemb, unsigned int size, char c);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *_cstrdup(const char *);

/* Functions inside buffer_functions.c */
int save_to_buffer(char **buffer, char *f_text);
char *extend_buffer(char *buffer, int extension);
char *init_buffer(void);


/* Functions inside apply_functions.c */
char *apply_prec(char *text, int prec);
char *apply_width(char *text, int width);
char *apply_flags(char *text, char *flags, char type);
int match(char c, char *str);

/* Functions inside apply_flag_functions.c */
char *apply_hash(char *text, char type);
char *apply_zero(char *text);
char *apply_sign(char *text);
char *apply_left_align(char *text);
char *apply_space(char *text);
/* char *(*num_func(char type, char len))(int {the va_arg num), char len);*/
/* char *(*str_func(char))(char *{the va arg string}) */
/*
 * char *apply_precision(char *str);
 * char *apply_width(char *str);
 * char *apply_flags(char *str);
 */
typedef struct formatting
{
	char *flags;
	int with, prec;
	char length, type;
} form_t;

typedef struct functions
{
	char t;
	void* (*f)(char length, va_list list);
} func_t;

void *_itoa(char length, va_list list);
void *_itoba(char length, va_list list);
void *_stoa(char length, va_list list);
void *_rtoa(char length, va_list list);
void *_bigrtoa(char length, va_list list);
void *_ctoa(char length, va_list list);
void *_utoa(char length, va_list list);
/*void *_otoa(char length, va_list list);*/
/*void *_xtoa(char length, va_list list);*/
/*void *_Xtoa(char length, va_list list);*/

void *(*func(char type))(char length, va_list list);
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
