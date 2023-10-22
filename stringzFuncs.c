#include "monty.h"

/**
 * _strcmp - Function to compare two strings.
 * @s1: type str compared
 * @s2: type str compared
 * Return: 0 if s1 and s2 are equals.
 *         another value if they are different
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] == s2[i] && s1[i]; i++)
		;
	if (s1[i] > s2[i])
		return (1);
	if (s1[i] < s2[i])
		return (-1);
	return (0);
}

/**
 * checkz_chr - function to search if a char is inside a string
 * @str: string to review
 * @ch: char to find
 * Return: 1 if success 0 if not
 */
int checkz_chr(char *str, char ch)
{
	int count = 0;

	while (str[count] != '\0')
	{
		if (str[count] == ch)
		{
			break;
		}
		count++;
	}
	if (str[count] == ch)
		return (1);
	else
		return (0);
}

/**
 * _strtkn - function to cut a string into tokens depending of the delimit
 * @str: string to cut in parts
 * @d: delimiters
 * Return: first partition
 */
char *_strtkn(char *str, char *d)
{
	static char *ult;
	int i = 0, j = 0;

	if (!str)
		str = ult;
	while (str[i] != '\0')
	{
		if (checkz_chr(d, str[i]) == 0 && str[i + 1] == '\0')
		{
			ult = str + i + 1;
			*ult = '\0';
			str = str + j;
			return (str);
		}
		else if (checkz_chr(d, str[i]) == 0 && checkz_chr(d, str[i + 1]) == 0)
			i++;
		else if (checkz_chr(d, str[i]) == 0 && checkz_chr(d, str[i + 1]) == 1)
		{
			ult = str + i + 1;
			*ult = '\0';
			ult++;
			str = str + j;
			return (str);
		}
		else if (checkz_chr(d, str[i]) == 1)
		{
			j++;
			i++;
		}
	}
	return (NULL);
}
