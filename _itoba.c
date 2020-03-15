#include <stdio.h>
#include "holberton.h"
long int mypow(int a, int b);

/**
*_itoba - takes an integer and returns it as a string
*Return: char pointer containing the sring number
*@number:the number taken in
*@length: whether the number is long or short int
*/

void *_itoba(char length, va_list list)
{
	long int number = va_arg(list, long int), numcpy = number;
	int i = 0, digits, sign = 1, signbuffer = 0;
	char *array, *newarray;

	
	(void) length;
	array =  _calloc(50, 1, 'n');
	if (array == NULL)
		return (NULL);
/*	printf("past calloc");*/
/*	if (number < 0)
	{
		array[0] = '-';
		sign = -1;
		signbuffer++;
	}*/
/*	printf("past neg check\n");*/
	for (digits = 1; digits < 50; digits++)
	{
		numcpy = numcpy / 2;
		if (numcpy == 0)
			break;
	}
/*	printf("got digits: %i\n",digits);*/
	for (digits--; digits >= 0; digits--)
	{
		array[digits + signbuffer] = '0' + number % 2 * sign;
		number /= 2;
		i++;
/*		printf("i:%i 1--array to now %s \n", i, array);*/
	}
	array[i + signbuffer] = '\0';
	i += signbuffer;
/*	printf("%s \n",array);*/
	newarray = _calloc(i + 1 + signbuffer, 1, '\0');
	for (; i >= 0; i--)
		newarray[i] = array[i];
	free(array);
	return ((char *)newarray);
}
