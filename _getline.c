#include "main.h"

/**
 * _getline - Takes a line of chars from input stream.
 * @line: the address of memory where the line will be stored.
 * @len: the number of chars in the line.
 * @stream: the address of the input stream.
 *
 * Return: the number of chars which are actually read.
 */
ssize_t _getline(char **line, size_t *len, FILE *stream)
{
	return (getline(line, len, stream));
}
