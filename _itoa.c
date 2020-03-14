#include <stdio.h>
#include "holberton.h"
long int mypow(int a, int b);

/**
*_itoa - takes an integer and returns it as a string
*@number:the number taken in
*@length: whether the number is long or short int
*/

void *_itoa(long int number, char length)
{
	int i = 0, digits, sign = 1;
	char *array;
	unsigned int memb = 22, size = 1;

	array =  _calloc(memb, size, '\0');
	if (array == NULL)
		return (NULL);
/*	printf("%s\n", array);*/
	if (number < 0)
	{
		array[0] = '-';
		sign = -1;
		i++;
	}
	for (digits = 1; digits < 19; digits++)
	{
/*		printf("%i\n", digits);*/
		if (number / mypow(10, digits) == 0)
			break;
	}
/*	printf("passed the first lopo\n");*/
/*	printf("sign is %i \n",sign);*/
	for (digits--; digits >= 0; digits--)
	{
/*		printf("%c : %i --\n", '0' + (int)(number / mypow(10, digits) % 10 * sign), i);*/
		array[i] = '0' + (int)(number / mypow(10, digits) % 10 * sign);
/*		printf("%c\n", 'p');*/
		i++;
	}
	array[i] = '\0';
	return ((char *)array);
	
}

/**
*mypow - exponent function
*Return: a to the power of b
*@a: number
*@b: exponent
*/
long int mypow(int a, int b)
{
	int i;
	long int r = 1;

	for (i = 0; i < b; i++)
		r = r * a;
	return (r);
}
