#include <stdio.h>
#include "holberton.h"
long int mypow(int a, int b);

/**
*_itoba - takes an integer and returns it as a string
*Return: char pointer containing the sring number
*@list:the list the number is drawn from
*@length: whether the number is long or short int
*/

void *_itoba(char length, va_list list)
{
	long int number = va_arg(list, long int), numcpy = number;
	int i = 0, digits, sign = 1;
	char *array, *newarray;

	(void) length;
	array =  _calloc(50, 1, 'n');
	if (array == NULL)
		return (NULL);

	for (digits = 1; digits < 50; digits++)
	{
		numcpy = numcpy / 2;
		if (numcpy == 0)
			break;
	}
	for (digits--; digits >= 0; digits--)
	{
		array[digits] = '0' + number % 2 * sign;
		number /= 2;
		i++;
	}
	array[i] = '\0';
	newarray = _calloc(i + 1, 1, '\0');
	if (newarray == NULL)
		return (NULL);
	for (; i >= 0; i--)
		newarray[i] = array[i];
	free(array);
	return ((char *)newarray);
}
/**
*_xtoa - converts unsigned int to hex array
*Return: the array or NULL
*@length: how long the int we take in is
*@list: list to draw the number from
*/
void *_xtoa(char length, va_list list)
{
	unsigned long int number, numcpy;
	int i = 0, digits;
	char *array;/*, *newarray;*/
	char *hex = "0123456789abcdef";

	if (length == 'l')
		number = va_arg(list, unsigned long int);
	else if (length == 'h')
		number = (unsigned short int)va_arg(list, int);
	else
		number = va_arg(list, unsigned int);
	numcpy = number;
	for (digits = 1; digits < 22; digits++)
	{
		numcpy /= 16;
		if (numcpy == 0)
			break;
	}
	array = _calloc(digits + 1, 1, 0);
	if (array == NULL)
		return (NULL);
	for (digits--; digits >= 0; digits--)
	{
		array[digits] = hex[number % 16];
		number /= 16;
		i++;
	}
	return (array);
}
/**
*_Xtoa - converts unsigned int to hex array
*Return: the array or NULL
*@length: how long the int we take in is
*@list: list to draw the number from
*/
void *_Xtoa(char length, va_list list)
{
	unsigned long int number, numcpy;
	int i = 0, digits;
	char *array;/*, *newarray;*/
	char *hex = "0123456789ABCDEF";

	if (length == 'l')
		number = va_arg(list, unsigned long int);
	else if (length == 'h')
		number = (unsigned short int)va_arg(list, int);
	else
		number = va_arg(list, unsigned int);
	numcpy = number;
	for (digits = 1; digits < 22; digits++)
	{
		numcpy /= 16;
		if (numcpy == 0)
			break;
	}
	array = _calloc(digits + 1, 1, 0);
	if (array == NULL)
		return (NULL);
	for (digits--; digits >= 0; digits--)
	{
		array[digits] = hex[number % 16];
		number /= 16;
		i++;
	}
	return (array);
}
/**
*_otoa - converts an unsigned int to an octal array
*Return: the char array of the number or NULL
*@length: length specifier for the unsigned int
*@list: the va list to get the number from
*/
void *_otoa(char length, va_list list)
{
	unsigned long int number, numcpy;
	int i = 0, digits;
	char *array;

	if (length == 'l')
		number = va_arg(list, unsigned long int);
	else if (length == 'h')
		number = (unsigned short int)va_arg(list, int);
	else
		number = va_arg(list, unsigned int);
	numcpy = number;
	for (digits = 1; digits < 30; digits++)
	{
		numcpy /= 8;
		if (numcpy == 0)
			break;
	}
	array = _calloc(digits + 1, 1, 0);
	if (array == NULL)
		return (NULL);
	for (digits--; digits >= 0; digits--)
	{
		array[digits] = '0' + number % 8;
		number /= 8;
		i++;
	}
	return (array);
}
/**
*_ptoa - converts a pointer to char array in hex
*Return: the array or null
*@length: not used for pointers
*@list: the va list to draw from
*/
void *_ptoa(char length, va_list list)
{
	unsigned long int number, numcpy;
	int i = 0, digits;
	char *array;
	char *hex = "0123456789abcdef";

	(void)length;
	number = va_arg(list, unsigned long int);
	numcpy = number;
	for (digits = 1; digits < 30; digits++)
	{
		numcpy /= 16;
		if (numcpy == 0)
			break;
	}
	array = _calloc(digits + 3, 1, 0);
	if (array == NULL)
		return (NULL);
	array[0] = '0';
	array[1] = 'x';
	for (digits++; digits >= 2; digits--)
	{
		array[digits] = hex[number % 16];
		number /= 16;
		i++;
	}
	return (array);
}
