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

	formats = malloc(sizeof(form_t));
	if (!formats)
		exit (1000);

	formats->flags = get_flags(fmt);
	formats->width = get_width(fmt);
	formats->prec = get_prec(fmt, args);
	formats->length = get_len(fmt);
	formats->type = get_type(fmt);

	return (formats);
}
