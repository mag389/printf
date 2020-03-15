#include "holberton.h"

/**
 * get_flags - get formatting flags
 * Description: Looks for each formatting flag (#, 0, +, -, ' ') and returns
 *              a pointer to a string with each present flag. Will move the
 *              pointer to the string given to it to look through.
 * @fmt: Formatting string to look through. Give a pointer to the index
 *       the function should start from.
 * Return: Pointer to string of flags present in the formatting string.
 *         The character will be present if the flag is present, or 'n'
 *         if the flag is not found. Flags are ordered as above.
*/

char *get_flags(char **fmt)
{
	char *flags;
	char *flag_list = "#0+- ";
	int index, found;

	flags = _calloc(6, 1, 'n');  /* Allocate space and fill with 'n' */
	if (!flags)
		return (NULL);
	*(flags + 5) = 0;            /* Replace last byte with null */

	while (*(++(*fmt)))
	{
		for (found = 0, index = 0; index < 5; index++)
		{
			if (**fmt == *(flag_list + index))
			{
				*(flags + index) = *(flag_list + index);
				found = 1;
			}
		}
		if (found == 0 && index < 6)
			return (flags);
	}
	if (*(flags + 2) == '+')
		*(flags + 4) = 'n';
	if (*(flags + 4) == ' ' || *(flags + 3) == '-')
		*(flags + 1) = 'n';
	return (flags);
}

/**
 * get_width - get width formatting
 * Description: Searches for a specified width that would follow the
 *              flags if present. Will move the pointer passed to it.
 * @fmt: Pointer to formatting string. Give at the position the function
 *       should start looking from.
 * Return: The specified width in the formatting string. 0 if no width found.
 */

int get_width(char **fmt)
{
	int width = 0;

	while (**fmt)
	{
		if (**fmt >= '0' && **fmt <= '9')
		{
			width *= 10;
			width += **fmt - 48;
			(*fmt)++;
		}
		else
			break;
	}
	return (width);
}

/**
 * get_len - get length formatting
 * Description: Gets the length specifier from the formatting string. Will move
 *              the pointer to the string.
 * @fmt: Pointer to formatting string. Give at the position the function
 *      should start looking from.
 * Return: Length character, or n if not present.
 */

char get_len(char **fmt)
{
	char length;

	if (**fmt == 'l' || **fmt == 'h')
		length = *(*fmt)++;    /* Save value and move pointer along */
	else
		length = 'n';
	return (length);
}

/**
 * get_type - get type specifier
 * Description: Gets the type specifier from the formatting string. Will move
 *              the pointer to the string.
 * @fmt: Pointer to formatting string. Give at the position the function
 *      should start looking from.
 * Return: Type character, or n if not present.
 */

char get_type(char **fmt)
{
	char type;

	if (**fmt == 'i' ||
	    **fmt == 'd' ||
	    **fmt == 'o' ||
	    **fmt == 'u' ||
	    **fmt == 'x' ||
	    **fmt == 'X' ||
	    **fmt == 'b' ||
	    **fmt == 's' ||
	    **fmt == 'S' ||
	    **fmt == 'r' ||
	    **fmt == 'R' ||
	    **fmt == 'c' ||
	    **fmt == 'p')
	{
		type = **fmt;
		(*fmt)++;
		return (type);
	}
	else
		return ('\0');
}

/**
 * get_prec - get precision formatting
 * Description:
 * @fmt: Pointer to formatting string. Give at the position the function
 *       should start looking from.
 * @args: The variadic list of arguments. Might be needed in case precision is
 *        specified with a '*'.
 * Return: Specified precision, or 0 if not found.
 */
int get_prec(char **fmt, va_list args)
{
	int prec = 0;
	if (**fmt == '.')
	{
		(*fmt)++;
		while(**fmt)
		{
			if (**fmt >= '0' && **fmt <= '9')
			{
				prec *= 10;
				prec += **fmt - 48;
				(*fmt)++;
			}
			else
				break;
		}
	}
	if (**fmt == '*')
	{
		(*fmt)++;
		return (va_arg(args, int));
	}
	return (prec);
}
