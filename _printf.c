#include "main.h"

/**
 * printBuffer - buffer if it exist
 * @buffer: input
 * @index: input
 */
void printBuffer(char buffer[], int *index)
{
	if (*index > 0)
		write(1, &buffer[0], *index);
	*index = 0;
}

/**
 * _printf - Printf function
 * @format: input.
 * Return: int
 */
int _printf(const char *format, ...)
{
	int i, print = 0, printChars = 0;
	int flag, width, prec, size, index = 0;
	va_list type;
	char buffer[BUFFER_SIZE];

	if (format == NULL)
		return (-1);

	va_start(type, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[index++] = format[i];
			if (index == BUFFER_SIZE)
				printBuffer(buffer, &index);
			printChars++;
		}
		else
		{
			printBuffer(buffer, &index);
			flag = getFlags(format, &i);
			width = getWidth(format, &i, type);
			prec = getPrecision(format, &i, type);
			size = getSize(format, &i);
			++i;
			print = handlePrint(format, &i, type, buffer,
				flag, width, prec, size);
			if (print == -1)
				return (-1);
			printChars += print;
		}
	}

	printBuffer(buffer, &index);

	va_end(type);

	return (printChars);
}

