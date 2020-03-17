#include "holberton.h"
#include <unistd.h>
/**
 * _free - free pointers
 * Description: Frees all pointers given to it
 * @n: Number of pointers to free
 */
void _free(int n, ...)
{
	va_list args;

	va_start(args, n);
	while(n--)
		free(va_arg(args, void *));
}
/**
 * save_to_buffer - save to buffer
 * Desciption: Appends a string to the end of the local buffer.
 * @buffer: Double pointer to local buffer. Needed as a double to extend with
 *          extend_buffer function.
 * @f_text: String of text to save to the buffer.
 * Return: The length of the string appended to the buffer.
 */
void save_to_buffer(char **buffer, char *f_text, int *buffer_index)
{
	int index;

	for (index = 0; *(f_text + index); index++, (*buffer_index)++)
	{
		if (*buffer_index % 1024 == 0 && *buffer_index != 0)
			write(1, *buffer, 1024);
		*(*buffer + (*buffer_index % 1024)) = *(f_text + index);
	}
}
