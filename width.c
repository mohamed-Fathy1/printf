#include "main.h"

/**
 * getWidth - width for printing
 * @fmt: input
 * @index: input
 * @type: input
 * Return: int
 */
int getWidth(const char *fmt, int *index, va_list type)
{
	int curr_i, width = 0;

	for (curr_i = *index + 1; fmt[curr_i] != '\0'; curr_i++)
	{
		if (isDigit(fmt[curr_i]))
		{
			width *= 10;
			width += fmt[curr_i] - '0';
		}
		else if (fmt[curr_i] == '*')
		{
			curr_i++;
			width = va_arg(type, int);
			break;
		}
		else
			break;
	}

	*index = curr_i - 1;

	return (width);
}
