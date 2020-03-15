#include "holberton.h"

/**
 * save_to_buffer - save to buffer
 * Description: Appends a string to the end of the local buffer.
 * @f_text: String of formatted text to append.
 * @buffer: Pointer to the buffer. Will be moved.
 */

void save_to_buffer(char *buffer, char *f_text)
{
	int i = 0;
	while (*f_text)
	{
		buffer[i] = *(f_text++);
		i++;
	}
}
