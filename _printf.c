#include "holberton.h"

/**
*_printf - prints formatted text
*Return: length of returned string
*format: the text with format specifiers
*/
int _printf(const char *format, ...)
{
	char *fmt_cpy;
	va_list args, args_cpy;
	char *buffer, *buffer_begin, *argtext, *flags, *chara;
	char type, len;
	int finlen, width;/*precision*/

	fmt_cpy = _cstrdup(format);
	buffer = malloc(500);
	chara = _calloc(2,1,'\0');
	if (buffer == NULL || chara == NULL)
		exit(1);
	buffer_begin = buffer;
	va_start(args, format);
	va_copy(args_cpy,args);
	while (*fmt_cpy)
	{
		if (*fmt_cpy == '%')
		{
			if (*(fmt_cpy + 1) == '%')
			{
				save_to_buffer(&buffer, "%");
				fmt_cpy += 2;
			}
			else
			{
				flags = get_flags(&fmt_cpy);
				get_width(&fmt_cpy);
/*				get_precision*/
				len = get_len(&fmt_cpy);
				type = get_type(&fmt_cpy);
				argtext = _itoa(va_arg(args, long int), len);
/*				if type is string call string f'n pointer
				if type is number call number f'n pointer
				apply_width() and precision
				apply_flags()
	
*/				save_to_buffer(&buffer, argtext);
				fmt_cpy++;
			}
		}
		else
		{
			chara[0] = *fmt_cpy;
			save_to_buffer(&buffer, chara);
			fmt_cpy++;
		}
	}
	*buffer = 0;
	finlen = _strlen(buffer_begin);
	printf("%s",buffer_begin);
	return(finlen);	
/*	write buffer to output
	free(everything allocated)
*/
}
