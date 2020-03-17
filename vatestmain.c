#include "holberton.h"
char *subfunction(char len, ...);
/* here's how i compiled:(there's a new line so cpy paste somewhere else first)
gcc -Wall -Werror -pedantic -Wextra _print* get_* _itoa* string_*
 _itoba.c _reall* buffer_functions.c agrtostr.c vat* str_* -g -o c*/
/*
*instructions: this file is for comparing subfuntions of 
*the poiinter function involved in printf
*to use: specify the number or string to be used by passing it as the 
*second argument of the subfunction in the main function
*(currently 1234)
*additionally length can be set in the subfunction return statement itself
*it takes 'l' or 'h', everything else is ignored
*/
int main(void)
{
	char *str;

	str = subfunction('n', 5000000000);
	printf("%s\n",str);
	free(str);
	str = subfunction('l',5000000000);
	printf("%s\n",str);
	free(str);
	printf("%X\n",(unsigned int)5000000000);
	printf("%lX\n",5000000000);
	printf("%x\n", 1);
	printf("%x\n", 1234);
	str = subfunction('h',5000000000);
	printf("%s\n", str);
	free(str);
	printf("%ho\n",(unsigned short int)5000000000);
	printf("%p\n",(void *) 1);
	printf("%p\n",&str[0]);
/* trying pointer */
	str = subfunction('n', 1);
	printf("%s\n", str);
	free(str);
	str = subfunction('n', &str[0]);
	printf("%s == %p\n", str, &str[0]);	
	return (1);
}

char *subfunction(char len, ...)
{
	va_list list;
	
	va_start(list, len);
	return(_ptoa(len, list));
	va_end(list);
}
