#include "holberton.h"

/**
 * apply_prec - apply precision
 * Description: Applies precision, if specified, to the text.
 * @text: String to format
 * @prec: Minimum number of leading zeros.
 * Return: Pointer to formatted text.
 */
char *apply_prec(char *text, int prec)
{
	int difference, index;
	char *prec_text;

	if (prec == 0 && _strlen(text) == 1 && *text == '0')
	{
		prec_text = _calloc(1, 1, '\0');
		if (!prec_text)
			exit(1000);
		free(text);
		return (prec_text);
	}

	difference = prec - _strlen(text);
	if (difference < 1)
		return (text);

	prec_text = _calloc(prec + 1, 1, '0');
	if (!prec_text)
		exit(1000);
	for (index = 0; *(text + index); index++)
		*(prec_text + difference + index) = *(text + index);
	*(prec_text + difference + index) = '\0';

	free(text);
	return (prec_text);
}
/**
 * apply_width - apply width
 * Description: Applies minimum field width, if specified, to the text.
 * @text: String to format
 * @width: Minimum field width
 * Return: Pointer to formatted text.
 */
char *apply_width(char *text, int width)
{
	int difference, index;
	char *wide_text;

	difference = width - _strlen(text);
	if (difference < 1)
		return (text);

	wide_text = _calloc(width + 1, 1, ' ');
	if (!wide_text)
		exit(1000);
	for (index = 0; *(text + index); index++)
		*(wide_text + difference + index) = *(text + index);
	*(wide_text + difference + index) = '\0';
	free(text);
	return (wide_text);
}

/**
 * match - character match
 * Description: Looks for a given character in a string.
 * @c: Character to look for
 * @str: String to look through
 * Return: 1 if a the character is found, 0 otherwise.
 */
int match(char c, char *str)
{
	int index;

	for (index = 0; *(str + index); index++)
	{
		if (*(str + index) == c)
			return (1);
	}
	return (0);
}
/*
char *apply_flags(char *text, char *flags, char type)
{
	if (*flags == '#' && match(type, "oxX"))
		text = apply_hash(text, type);
	if (*(flags + 1) == '0' && match(type, "diuoxX"))
		text = apply_zero(text);
	if (*(flags + 2) == '+' && match(type, "di"))
		text = apply_sign(text);
	if (*(flags + 3) == '-')
		text = apply_left_align(text);
	if (*(flags + 4) == ' ' && match(type, "di"))
		text = apply_space(text);
	return (text);
}
*/
