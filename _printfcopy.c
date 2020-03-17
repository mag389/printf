#include <unistd.h>
#include "holberton.h"

/**
*_printf - prints formatted text
*Return: length of returned string
*format: the text with format specifiers
*/
int _printft(const char *format, ...)
{
	char *fmt_cpy, *buffer, *argtext, *chara;
	va_list args, args_cpy;
	int buffer_length = 0;
	int fmt_len;
	void *(*funct)(char, va_list);
	form_t *format_s;

	fmt_cpy = _cstrdup(format);
	fmt_len = _strlen(fmt_cpy);
	buffer = malloc(1014);
	chara = _calloc(2,1,'\0');
	if (buffer == NULL || chara == NULL)
		exit(1);
	va_start(args, format);
	va_copy(args_cpy,args);
	while (*fmt_cpy)
	{
		if (*fmt_cpy == '%')
		{
			if (*(fmt_cpy + 1) == '%')
			{
				save_to_buffer(&buffer, "%", &buffer_length);
				fmt_cpy += 2;
			}
			else
			{
				format_s = get_formatting(&fmt_cpy, args_cpy);
				funct = (*func)(format_s->type);
				argtext = funct(format_s->length, args);
				argtext = apply_formatting(argtext, format_s);
			        save_to_buffer(&buffer, argtext, &buffer_length);
				free(argtext);
				free(format_s->flags);
				free(format_s);
			}
		}
		else
		{
			chara[0] = *fmt_cpy;
			save_to_buffer(&buffer, chara, &buffer_length);
			fmt_cpy++;
		}
	}
	if (buffer_length % 1024 != 0)
		write(1, buffer, (buffer_length % 1024));
	free(fmt_cpy - fmt_len);
	free(buffer);
	free(chara);
	return(buffer_length);
}
