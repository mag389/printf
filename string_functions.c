#include "holberton.h"
#include <stdlib.h>

/**
 * _strdup - string duplicate
 * Description: Duplicates a string
 * @str: Source string
 * Return: Pointer to newly created string
 */

char *_strdup(char *str)
{
	int index, size;
	char *dst;

	if (str == NULL)
		return (NULL);

	size = 0;
	while (*(str + size))
		size++;

	dst = malloc(size + 1);
	if (dst == NULL)
		return (NULL);

	for (index = 0; index < size; index++)
		*(dst + index) = *(str + index);

	*(dst + index) = '\0';

	return (dst);
}

/**
 * _calloc - character allocate
 * Description: Allocates memory for an array and sets each element to zero
 * @nmemb: Number of elements in the array
 * @size: Size of each element
 * @c: character with which to fill each byte
 * Return: Pointer to allocated memory, or NULL if unsuccessful.
 */

void *_calloc(unsigned int nmemb, unsigned int size, char c)
{
	char *pointer;
	unsigned int index;

	if (nmemb == 0 || size == 0)
		return (NULL);

	pointer = malloc(nmemb * size);
	if (pointer == NULL)
		return (NULL);

	for (index = 0; index < nmemb * size; index++)
		*(pointer + index) = c;

	return ((void *)pointer);
}

/**
 * _strlen - Returns lenght of a string
 * @s: Incoming string
 * Description: Counts the number of charaters in a string, returns that number
 * Return: Length of the string
 */

int _strlen(char *s)
{
	int strlen = 0;

	while (*(s + strlen))
		strlen++;

	return (strlen);
}
/**
 * _cstrdup - string duplicate
 * Description: Duplicates a string
 * @str: Source string
 * Return: Pointer to newly created string
 */

char *_cstrdup(const char *str)
{
	int index, size;
	char *dst;

	if (str == NULL)
		return (NULL);

	size = 0;
	while (*(str + size))
		size++;

	dst = malloc(size + 1);
	if (dst == NULL)
		return (NULL);

	for (index = 0; index < size; index++)
		*(dst + index) = *(str + index);

	*(dst + index) = '\0';

	return (dst);
}
