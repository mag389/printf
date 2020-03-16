#include "holberton.h"

/**
 * apply_zero - apply zero formatting
 * Description: Applies '0' formatting to a given string.
 * @text: String to be formatted
 * Return: Formatted string
 */
char *apply_zero(char *text)
{
	int index = 0;
	while (*(text + index))
	{
		if (*(text + index) != ' ')
			break;
		*(text + index) = '0';
		index++;
	}
	if (*(text + index) == '-')
	{
		*(text + index) = '0';
		*text = '-';
	}
	return (text);
}


/**
 * apply_hash - apply '#' formatting
 * Description: Puts a leading 0 in front of octal conversions if the first
 *              digit isn't already a 0. Puts a leading 0x for x conversions,
 *              or a leading 0X for X conversions.
 * @text: String to format
 * @type: Type specifier, should only be o, x, or X
 * Return: Formatted text
 */
char *apply_hash(char *text, char type)
{
	char *hash_text;
	int index;

	if (type == 'o')
	{
		if (*text == '0')
			return (text);

		hash_text = _calloc(_strlen(text) + 2, 1, '\0');
		if (!hash_text)
			exit(1000);
		*hash_text = '0';
		for (index = 0; *(text + index); index++)
			*(hash_text + index + 1) = *(text + index);
		free(text);
		return (hash_text);
	}
	else
	{
		hash_text = _calloc(_strlen(text) + 3, 1, '\0');
		if (!hash_text)
			exit(1000);
		*hash_text = '0';
		*(hash_text + 1) = (type == 'x' ? 'x' : 'X');
		for (index = 0; *(text + index); index++)
			*(hash_text + index + 2) = *(text + index);
		free(text);
		return (hash_text);
	}
}

/**
 * apply_sign - apply sign
 * Description: Applies either + or ' ' formatting to a string.
 * @text: String to be formatted
 * @flags: String of formatting flags present in parent formatting string.
 * Return: Formatted text
 */
char *apply_sign(char *text, char *flags)
{
	char *sign_text;
	int index;
	char flag;

	flag = (*(flags + 2) == '+' ? '+' : ' ');
	if (*text == '-')
		return (text);
	if (*text == ' ')
	{
		while (*(text + index) == ' ')
			index++;
		*(text + index - 1) = '+';
		return (text);
	}
	if (*text == '0')
	{
		*text = flag;
		return (text);
	}

	sign_text = _calloc(_strlen(text) + 2, 1, '\0');
	if (!sign_text)
		exit (1000);
	*sign_text = flag;
	for (index = 0; *(text + index); index++)
		*(sign_text + index + 1) = *(text + index);
	free(text);
	return (sign_text);
}
