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
		{'u', _utoa},
		{'S', _bigstoa},
		{'x', _xtoa},
		{'X', _Xtoa},
		{'o', _otoa},
		{'p', _ptoa},
		{0, NULL}
	};
	int i;

	i = 0;
	while (i < 13)
	{
		if (t == ((fns + i)->t))
			return ((fns + i)->f);
		i++;
	}
	return (NULL);
}
