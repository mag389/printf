#include <unistd.h>
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
	int finlen, width, index = 0;/*precision*/

	fmt_cpy = _cstrdup(format);
	printf("----------------------\n%s\n",fmt_cpy);
	buffer = malloc(500);
	chara = _calloc(2,1,'\0');
	if (buffer == NULL || chara == NULL)
		exit(1);
	buffer_begin = &(buffer[0]);
	va_start(args, format);
	va_copy(args_cpy,args);
	printf("----------------------------------------\n");
	while (*fmt_cpy)
	{
/*		printf("makes it into the while loop\n");*/
		if (*fmt_cpy == '%')
		{
			if (*(fmt_cpy + 1) == '%')
			{
				printf("the char is: %c\n", *fmt_cpy);
				save_to_buffer(&buffer[index], "%");
				printf("trying a print iside the if %s\n", buffer);
				fmt_cpy += 2;
				index += 1;
			}
			else
			{
				printf("the char is: %c\n", *fmt_cpy);
				flags = get_flags(&fmt_cpy);
				get_width(&fmt_cpy);
/*				get_precision
				len = get_len(&fmt_cpy);*/
				type = get_type(&fmt_cpy);
				(void)width;
				(void)flags;
				(void)type;
				(void)len;
				argtext = _itoa('l', args);
				printf("the argtext is: %s\n",argtext);
/*				if type is string call string f'n pointer
				if type is number call number f'n pointer
				apply_width() and precision
				apply_flags()
	
*/				save_to_buffer(&buffer[index], argtext);
				fmt_cpy++;
				printf("the arglength in: %i\n",_strlen(argtext));
				index += _strlen(argtext);
			}
		}
		else
		{
			chara[0] = *fmt_cpy;
			save_to_buffer(&buffer[index], chara);
			fmt_cpy++;
			index += 1;
		}
	}
	printf("index is: %i\n", index);
	buffer[index] = 0;
	finlen = _strlen(buffer_begin);
	printf("length is %i\n______",finlen);
	write(1, buffer, index);
	printf("_____\ni just tried to write\nbuffer begin - index is %s\n",buffer);
	printf("printing just buffer: %s\n", (buffer));
	printf("and buffer begin: %s\n",buffer_begin - 2);
	return(finlen);	
/*	write buffer to output
	free(everything allocated)
*/
}
