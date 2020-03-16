#include <stdio.h>
#include "holberton.h"
long int mypow(int a, int b);

/**
*_itoa - takes an integer and returns it as a string
*Return: char pointer containing the sring number
*@list:the list to get num from
*@length: whether the number is long or short int
*/

void *_itoa(char length, va_list list)
{
	int i = 0, digits, sign = 1;
	char *array, *newarray;
	long int number;

	if (length == 'l')
		number = va_arg(list, long int);
	else if (length == 'h')
		number = (short int)va_arg(list, int);
	else
		number = va_arg(list, int);
	array =  _calloc(22, 1, 'n');
	if (array == NULL)
		return (NULL);
	if (number < 0)
	{
		array[0] = '-';
		sign = -1;
		i++;
	}
	for (digits = 1; digits < 19; digits++)
	{
		if (number / mypow(10, digits) == 0)
			break;
	}
	for (digits--; digits >= 0; digits--)
	{
		array[i] = '0' + (int)(number / mypow(10, digits) % 10 * sign);
		i++;
	}
	array[i] = '\0';
	newarray = _calloc(i + 1, 1, '\0');
	for (; i >= 0; i--)
		newarray[i] = array[i];
	free(array);
	return ((char *)newarray);
}
/**
*_utoa - unsigned int to array
*Return: the array containing the unsigned int
*@length: not yet put in
*@list: the valist to get the unsigned int from
*/
void *_utoa(char length, va_list list)
{
	int i = 0, digits;
	char *array, *newarray;
	unsigned long int number;
	unsigned long int numcpy;

	if (length == 'l')
		number = va_arg(list, unsigned long int);
	else if (length == 'h')
		number = (unsigned short int)va_arg(list, int);
	else
		number = va_arg(list, unsigned int);
	numcpy = number;
	array =  _calloc(22, 1, 'n');
	if (array == NULL)
		return (NULL);
	for (digits = 1; digits < 20; digits++)
	{
		numcpy /= 10;
		if (numcpy == 0)
			break;
	}
	for (digits--; digits >= 0; digits--)
	{
		printf("%s\n", array);
		array[digits] = '0' + number % 10;
		number /= 10;
		i++;
	}
	array[i] = '\0';
	newarray = _calloc(i + 1, 1, '\0');
	if (newarray == NULL)
		exit(3);
	for (; i >= 0; i--)
		newarray[i] = array[i];
	free(array);
	return ((char *)newarray);
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
