#include <stdio.h>
#include "holberton.h"
long int mypow(int a, int b);

/**
*_itoa - takes an integer and returns it as a string
*Return: char pointer containing the sring number
*@number:the number taken in
*@length: whether the number is long or short int
*/

void *_itoa(long int number, char length)
{
	int i = 0, digits, sign = 1;
	char *array, *newarray;

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
