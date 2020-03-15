#include "holberton.h"

/**
*func - chooses the function for writing the argument to string
*@t: the type character of the argument
*Return: the function
*takes in a char, returns a f'n that take list and char len
*/

void *(*func(char t))(char len, va_list list)
{
	func_t fns[] = {
		{'i', _itoa},
		{'b', _itoba},
		{'d', _itoa},
		{'s', _stoa},
		{'c', _ctoa},
		{'r', _rtoa},
		{'R', _bigrtoa},
		{0, NULL}
/* 		todo: S, uoxX*/
	};
	int i;

	i = 0;
	while (i < 7)
	{
		if (t == ((fns + i)->t))
			return ((fns + i)->f);
		i++;
	}
	return (NULL);
}
