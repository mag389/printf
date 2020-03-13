#include "holberton.h"

/**
*_printf - prints formatted text
*Return: length of returned string
*format: the text with format specifiers
*/
int _printf(const char *format, ...)
{
	char *fmt_cpy = format;

	while (*fmt_cpy)
/*	{
	if (*fmt_cpy = '%')
	{
		if (*(fmt_cpy + 1) = '%')
			write a % symbol to the buffer
			increment fmt_cpy past the second %
		else
			get_flags();
			get width
			get_precision
			get_len
			get_type
			if type is string call string f'n pointer
			if type is number call number f'n pointer
			apply_width() and precision
			apply_flags()

			for new string length
				save to buffer
				make this it's own function
	}
	else
		add the character that's not % to buffer
	fmt_cpy++;
	}
	strlen new buffer
	write buffer to output
	free(everything allocated)
	return that length
*/
}
