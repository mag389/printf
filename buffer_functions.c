#include "holberton.h"

char *extend_buffer(char *buffer, int extension)
{
	int buffer_size, new_size;
	char *new_buffer;

	buffer_size = _strlen(buffer) + 1;
	new_size = buffer_size + extension;
	new_buffer = _realloc(buffer, buffer_size, new_size);
	return(new_buffer);
}

char *init_buffer(void)
{
	char *buffer;
	buffer = _calloc(1, 1, '\0');
	if(!buffer)
		return (NULL);
	return (buffer);
}

int save_to_buffer(char **buffer, char *f_text)
{
	int f_text_len, index, old_buffer_len;

	old_buffer_len = _strlen(*buffer);
	f_text_len = _strlen(f_text);

	*buffer = extend_buffer(*buffer, f_text_len);
	if(!buffer)
		return (0);
	for (index = 0; *(f_text + index); index++)
		*(*(buffer) + old_buffer_len + index) = *(f_text + index);
	*(*(buffer) + old_buffer_len + index) = '\0';
	/* free(f_text); */
	return(f_text_len);
}
