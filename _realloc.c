#include <stdio.h>
#include <stdlib.h>
#include "holberton.h"

/**
*_realloc - reallocates memory
*Return: new memory block or null
*@ptr: pointer to prev allocated memory
*@old_size: the size of old ptr
*@new_size: size of new memory block
*/
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *newptr;
	unsigned int i, min;
	char *chptr = (char *)ptr;

	if (ptr == NULL)
		return (malloc(new_size));
	else if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	if (new_size == old_size)
		return (ptr);
	min = old_size;
	if (new_size < old_size)
		min = old_size;

	newptr = malloc(new_size);
	if (newptr == NULL)
		{
		return (NULL);
		}
	for (i = 0; i < min; i++)
		newptr[i] = chptr[i];
	free(ptr);
	return (newptr);
}
