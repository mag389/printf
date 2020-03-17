#include <unistd.h>
#include "holberton.h"
/**
*_printf - prints formatted text
*Return: length of returned string
*@format: the text with format specifiers
*/
int _printf(const char *format, ...)
{
	char *fmt_cpy, *buffer, *argtext, *chara;
	va_list args, args_cpy;
	int buffer_len = 0, fmt_len;
	void *(*funct)(char, va_list);
	form_t *format_s;

	if (!format)
		return (-1);
	va_start(args, format);
	va_copy(args_cpy, args);
	if (check_val(_cstrdup(format), args_cpy) == 0)
		return (-1);
	fmt_cpy = _cstrdup(format);
	fmt_len = _strlen(fmt_cpy);
	buffer = malloc(1024);
	chara = _calloc(2, 1, '\0');
	if (buffer == NULL || chara == NULL)
		exit(1);

	while (*fmt_cpy)
	{
		if (*fmt_cpy == '%')
		{
			if (*(fmt_cpy + 1) == '%')
			{
				save_to_buffer(&buffer, "%", &buffer_len);
				fmt_cpy += 2;
			}
			else
			{
				format_s = get_formatting(&fmt_cpy, args);
				funct = (*func)(format_s->type);
				argtext = funct(format_s->length, args);
				if (!argtext)
				{
					_free(4, buffer, format_s->flags,
					      format_s, chara);
					return (-1);
				}
				argtext = apply_formatting(argtext, format_s);
				if (!argtext)
				{
					_free(4, buffer, format_s->flags,
					      format_s, chara);
					return (-1);
				}
			        save_to_buffer(&buffer, argtext, &buffer_len);
				_free(3, argtext, format_s->flags, format_s);
			}
		}
		else
		{
			chara[0] = *fmt_cpy;
			save_to_buffer(&buffer, chara, &buffer_len);
			fmt_cpy++;
		}
	}
	if (buffer_len % 1024 != 0)
		write(1, buffer, (buffer_len % 1024));
	_free(3, (fmt_cpy - fmt_len), buffer, chara);
	return(buffer_len);
}
