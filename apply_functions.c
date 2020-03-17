#include "holberton.h"
/**
 * apply_formatting - apply formatting
 * Description: Applies all specified formatting to a string of text.
 * @text: String to be formatted
 * @format: Struct containing formatting information
 * Return: Formatted text
 */
char *apply_formatting(char *text, form_t *format)
{
	if (!text)
		return (NULL);
	text = apply_width(text, format->width);
	if (format->prec >= 0)
		text = apply_prec(text, format->prec);
	text = apply_flags(text, format->flags, format->type);
	return (text);
}
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
	if (!text)
		return (NULL);
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
		return (NULL);
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

	if (!text)
		return (NULL);
	difference = width - _strlen(text);
	if (difference < 1)
		return (text);

	wide_text = _calloc(width + 1, 1, ' ');
	if (!wide_text)
		return (NULL);
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

char *apply_flags(char *text, char *flags, char type)
{
	if (!text)
		return (NULL);
	if (*(flags + 1) == '0' && match(type, "diuoxX"))
		text = apply_zero(text);
	if (!text)
		return (NULL);
	if (*flags == '#' && match(type, "oxX"))
		text = apply_hash(text, type);
	if (!text)
		return (NULL);
	if ((*(flags + 2) == '+' || *(flags + 4) == ' ') && match(type, "di"))
		text = apply_sign(text, flags);
	if (!text)
		return (NULL);
	if (*(flags + 3) == '-')
		text = apply_left_align(text);
	if (!text)
		return (NULL);
	return (text);
}
