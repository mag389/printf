#include "holberton.h"

/**
*_stoa: takes a string and returns that string
*Return: a string of characters
*@len: unused
*@list: where to draw the string from
*/
void *_stoa(char len, va_list list)
{
	char *str;

	(void)len;
	str = _strdup(va_arg(list char *));
	if (str == NULL)
		exit(2);
	return (str);
}
/**
*_rtoa - reverses the string
*Return: a string of chars
*@len: unused
*@list: the list to draw str from
*/
void *_rtoa(char len, va_list list)
{
	char *str, temp;
	int i, length;

	(void)len;
	str = _strdup(va_arg(list, char *));
	if(str == NULL)
		exit(2);
	length = _strlen(str);
	for (i = 0; i <= length / 2; i++)
	{
		temp = str[i];
		str[i] = str[length - 1 - i];
		str[length - 1 - i] = temp;
	}
	return (str);
}
/**
*_bigrtoa - rot13's the string
*Return: string of chars or NULL
*@len:unused
*@list:list to draw string from
*/
void *_bigrtoa(char len, va_list list)
{
	char *str, temp;
	int i, j;
	char *low = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char *high = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";

	(void)len;
	str = _strdup(va_arg(list, char *));
	if (str == NULL)
		exit(2);
	for(i = 0; str[i] != '\0'; i++)
	{
		for (j = 0; j < 52; j++)
		{
			if (str[i] == low[j])
			{
				a[i] = high[j];
				break;
			}
		}
	}
	return (str);
}
/**
*_bigstoa - returns the string with special chars displayed differently
*Return: string of chars or NULL
*@len: unused
*@list: list to draw string from
*/
/*
void *_bigstoa(char len, va_list list)
{
	char *str;
	int i, length;

	(void)len;
	str = _strdup(va_arg(list char *));
	if (str == NULL)
		exit(2);
	for (i = 0; i < length; i++)

	return (str);
}
*/
/**
*_ctoa - returns the character as a string
*Return: string of char or NULL
*@len: unused
*@list: list to draw the char from
*/
void *_ctoa(char len, va_list list)
{
	char *str;

	str = _calloc(2,1,'\0');
	if (str == NULL)
		exit(3);
	str[0] = va_arg(list, char);
	return (str);
}
