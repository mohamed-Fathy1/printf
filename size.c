#include "main.h"

/**
 * getSize - size to cast the argument
 * @fmt: input
 * @index: input
 * Return: Precision.
 */
int getSize(const char *fmt, int *index)
{
	int curr_i = *index + 1, size = 0;

	if (fmt[curr_i] == 'l')
		size = LONG;
	else if (fmt[curr_i] == 'h')
		size = SHORT;

	if (size == 0)
		*index = curr_i - 1;
	else
		*index = curr_i;

	return (size);
}

