#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct formatting
{
	char *flags;
	int width, prec;
	char length, type;
} form_t;

int _printf(const char *format, ...);

/* Functions inside get_functions.c */
char *get_flags(char **fmt);
int get_width(char **fmt, va_list args);
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
void save_to_buffer(char **buffer, char *f_text, int *buffer_length);
void _free(int n, ...);
int check_val(char *fmt, va_list args);

/* Functions inside apply_functions.c */
char *apply_formatting(char *text, form_t *format);
char *apply_prec(char *text, int prec);
char *apply_width(char *text, int width);
char *apply_flags(char *text, char *flags, char type);
int match(char c, char *str);

/* Functions inside apply_flag_functions.c */
char *apply_hash(char *text, char type);
char *apply_zero(char *text);
char *apply_sign(char *text, char *flags);
char *apply_left_align(char *text);

typedef struct functions
{
	char t;
	void* (*f)(char length, va_list list);
} func_t;

form_t *get_formatting(char **fmt, va_list args);

void *_itoa(char length, va_list list);
void *_itoba(char length, va_list list);
void *_stoa(char length, va_list list);
void *_rtoa(char length, va_list list);
void *_bigrtoa(char length, va_list list);
void *_ctoa(char length, va_list list);
void *_utoa(char length, va_list list);
void *_bigstoa(char length, va_list list);
void *_otoa(char length, va_list list);
void *_xtoa(char length, va_list list);
void *_Xtoa(char length, va_list list);
void *_ptoa(char length, va_list list);

void *(*func(char type))(char length, va_list list);


#endif
