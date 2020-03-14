#include <stdio.h>
#include <limits.h>
#include "holberton.h"

int main(void)
{
/*	long int number;
	int i;
	char *ary;
*/
/*	printf("%li\n",12345);wont compile type error*/
/*        printf("%hi\n",123456789);*/
/*	printf("%  i",10); won't compile two spaces error */
/*	printf("%5i\n",123456);
	printf("the number is %x and the next number is \n",123);
	printf("%#x\n",123);
        printf("% i\n",123);
	printf("%i\n", 123);
	printf("%5i\n", 123);
        printf("% 5i\n", 123);
	printf("%-10s\n","hello");
	printf("%+05i\n", -56);

	i = 7;
	number = i;	
	printf("%li", number);
	i = number;
	printf("%i\n", i);
	printf("%i\n", -7 % 10);
	printf("%li\n",LONG_MAX);
	ary = _itoa(1234,'l');
	printf("the first call %s\n", ary);
	free(ary);
	ary = _itoa(-1234,'l');
	printf("the second call %s\n", ary);
	free(ary);
	ary = _itoa(123456789,'l');
	printf("%s\n", ary);
	free(ary);
	ary = _itoa(LONG_MAX, 'l');
	printf("%s\n", ary);
	free(ary);
	ary = _itoa(-123456789,'l');
	printf("%s\n", ary);
	free(ary);
	ary = _itoba(1234,'l');
	printf("%s\n",ary);
	free(ary);
*/
	printf("lets see if our printf works:\n");
	_printf("hello");
	_printf("hi%%");
	_printf("hi%i",7);
	return (0);
}
