#include "holberton.h"

/**
 * get_formatting - get formatting
 * Description: Searches through the given string, starting at a '%', and
 *              returns a pointer to a struct containing the given flags,
 *              width, precision, length, and type formats for the next
 *              argument. Will move the pointer of the string it is given.
 *              Will need the struct and its flags member freed.
 *
 * @fmt: Double pointer to the formatting string to look through.
 * @args: va_list containing the arguments given to _printf. Needed in
 *        case precision is specified with a '*'.
 * Return: Pointer to allocated and filled formatting struct.
 */
form_t *get_formatting(char **fmt, va_list args)
{
	form_t *formats;

	formats = malloc(24);
	if (!formats)
		return (NULL);

	formats->flags = get_flags(fmt);
	if (!formats->flags)
	{
		free(formats);
		return (NULL);
	}
	formats->width = get_width(fmt, args);
	formats->prec = get_prec(fmt, args);
	formats->length = get_len(fmt);
	formats->type = get_type(fmt);
	if(formats->type == 0)
	{
		free(formats->flags);
		free(formats);
		return (NULL);
	}
	return (formats);
}
