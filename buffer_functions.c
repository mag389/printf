#include "holberton.h"
#include <unistd.h>
/**
 * extend_buffer - extend buffer
 * Description: Extends the allocated space of the buffer by reallocating
 *              a new space equal to the current size of the buffer and
 *              the amount to extend it by, and copies the contents of the
 *              buffer into the new space.
 *
 * @buffer: Pointer to buffer to extend.
 * @extension: Number of bytes by whuch to extend the buffer.
 * Return: Pointer to new buffer space.
 */
char *extend_buffer(char *buffer, int extension)
{
	int buffer_size, new_size;
	char *new_buffer;

	buffer_size = _strlen(buffer) + 1;
	new_size = buffer_size + extension;
	new_buffer = _realloc(buffer, buffer_size, new_size);
	return (new_buffer);
}

/**
 * init_buffer - initialize buffer
 * Description: Callocs a single null byte to start the buffer with. Mainly
 *              just to save lines in _printf.
 * Return: Pointer to allocated buffer.
 */
char *init_buffer(void)
{
	char *buffer;

	buffer = malloc(1024);
	if (!buffer)
		exit(1000);
	return (buffer);
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
