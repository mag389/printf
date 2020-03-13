#ifndef HOLBERTON_H
#define HOLBERTON_H

int _strlen(char *str);
void *_calloc(char c, unsigned int n);
/* atoi */ 
char *get_flags(char *fmt);
int get_width(char *fmt);
int get_prec(char *fmt);
char get_len(char *fmt);
char get_type(char *fmt);

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
