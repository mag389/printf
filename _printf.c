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
	char *buffer, *argtext, *flags, *chara;
	char type, len;
	int width;/*precision*/
	int buffer_length = 0;
	void *(*funct)(char, va_list);

	fmt_cpy = _cstrdup(format);
	printf("----------------------\n%s\n",fmt_cpy);
	buffer = malloc(1024);
	chara = _calloc(2,1,'\0');
	if (buffer == NULL || chara == NULL)
		exit(1);
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
				save_to_buffer(&buffer, "%", &buffer_length);
				printf("trying a print iside the if %s\n", buffer);
				fmt_cpy += 2;
			}
			else
			{
				printf("the char is: %c\n", *fmt_cpy);
				flags = get_flags(&fmt_cpy);
				get_width(&fmt_cpy);/*
				get_precision*/
				len = get_len(&fmt_cpy);
				type = get_type(&fmt_cpy);
				(void)width;
				(void)flags;
				(void)type;
				printf("the type is: %c\n",type);
				funct = (*func)(type);
				argtext = funct(len, args);
				printf("the argtext is: %s\n",argtext);
/*				if type is string call string f'n pointer
				if type is number call number f'n pointer
				apply_width() and precision
				apply_flags()

*/			        save_to_buffer(&buffer, argtext, &buffer_length);
				free(argtext);
/*				fmt_cpy++;*/
				printf("the arglength in: %i\n",_strlen(argtext));
			}
		}
		else
		{
/*			printf("gets to chara (%s) part \n", chara);*/
			chara[0] = *fmt_cpy;
/*			printf("the chara is %s the buffer %s\n", chara, buffer);*/
			save_to_buffer(&buffer, chara, &buffer_length);
			fmt_cpy++;
/*			printf("breaks somewhere here\n");*/
		}
	}
	printf("length is %i should be %i \n_____\n",buffer_length, _strlen(buffer));
	if (buffer_length % 1024 != 0)
		write(1, buffer, buffer_length);
	printf("\ni just tried to write\nbuffer begin - index is %s\n",buffer);
	printf("printing just buffer: %s\n", (buffer));
	free(buffer);
	return(buffer_length);
/*	write buffer to output
	free(everything allocated)
*/
}
