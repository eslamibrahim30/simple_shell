#include "main.h"

/**
 * _strcmp - Compare two given strings
 * @s1: first string
 * @s2: second string
 *
 * Return: 0 if they are qual, +ve if s1>s2 or -ve if s1<s2
 */
int _strcmp(char *s1, char *s2)
{
	int idx1;
	int idx2;

	idx1 = 0;
	idx2 = 0;
	while (s1[idx1] != '\0' && s2[idx2] != '\0')
	{
		if (s1[idx1] != s2[idx2])
		{
			return ((int)(s1[idx1] - s2[idx2]));
		}
		idx1++;
		idx2++;
	}
	if (s1[idx1] != '\0')
	{
		return ((int)(s1[idx1]));
	}
	else if (s2[idx2] != '\0')
	{
		return (-1 * (int)(s2[idx2]));
	}
	else
	{
		return (0);
	}
}

/**
 * _strtok - Splits a string according to a specified delimiter.
 * @str: the given string to be splitted.
 * @delim: the given delimiter.
 *
 * Return: a string which is before the delimiter.
 */
char *_strtok(char *str, char *delim)
{
	return (strtok(str, delim));
}

/**
 * _atoi - Convert a given string to integer
 * @s: the given string
 *
 * Return: an integer value
 */
int _atoi(char *s)
{
	int start;
	int value;
	int add;
	int minus_sign;

	start = 0;
	value = 0;
	add = 0;
	minus_sign = 0;
	while (!(*(s + start) >= '0' && *(s + start) <= '9'))
	{
		if (*(s + start) == '-')
		{
			minus_sign++;
		}
		start++;
		if (*(s + start) == '\0')
		{
			return (0);
		}
	}
	while (*(s + start) >= '0' && *(s + start) <= '9')
	{
		value *= 10;
		add = (*(s + start) - '0');
		add *= (minus_sign % 2 == 0 ? 1 : -1);
		value += add;
		start++;
	}
	return (value);
}
