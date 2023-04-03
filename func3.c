#include "main.h"



/**
 * printReverse - reverse string.
 * @type: input
 * @buffer: input
 * @flag: input
 * @width: input
 * @prec: input
 * @size: input
 * Return: int
 */
int printReverse(va_list type, char buffer[],
	int flag, int width, int prec, int size)
{
	char *p;
	int i, j = 0;

	NOT_USED(buffer);
	NOT_USED(flag);
	NOT_USED(width);
	NOT_USED(prec);
	NOT_USED(size);

	p = va_arg(type, char *);
	if (p == NULL)
	{
		p = ")Null(";
	}
	for (i = 0; p[i]; i++)
		;
	for (i = i - 1; i >= 0; i--)
	{
		char x = p[i];

		write(1, &x, 1);
		j++;
	}
	return (j);
}


/**
 * print_nonPrintable - hexa of non printable chars
 * @type: input
 * @buffer: input
 * @flag: input
 * @width: input
 * @prec: input
 * @size: input
 * Return: input
 */
int print_nonPrintable(va_list type, char buffer[],
	int flag, int width, int prec, int size)
{
	int i = 0, offset = 0;
	char *p = va_arg(type, char *);

	NOT_USED(flag);
	NOT_USED(width);
	NOT_USED(prec);
	NOT_USED(size);

	if (p == NULL)
		return (write(1, "(null)", 6));

	while (p[i] != '\0')
	{
		if (isPrintable(p[i]))
			buffer[i + offset] = p[i];
		else
			offset += appendHexaCode(p[i], buffer, i + offset);

		i++;
	}

	buffer[i + offset] = '\0';
	return (write(1, buffer, i + offset));
}




/**
 * printRot13 - string in rot13.
 * @type: input
 * @buffer: input
 * @flag: input
 * @width: input
 * @prec: input
 * @size: Size specifier
 * Return: int
 */
int printRot13(va_list type, char buffer[],
	int flag, int width, int prec, int size)
{
	char z;
	char *p;
	unsigned int i, j;
	int c = 0;
	char real[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char rot[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	p = va_arg(type, char *);
	NOT_USED(buffer);
	NOT_USED(flag);
	NOT_USED(width);
	NOT_USED(prec);
	NOT_USED(size);

	if (p == NULL)
		p = "(AHYY)";
	for (i = 0; p[i]; i++)
	{
		for (j = 0; real[j]; j++)
		{
			if (real[j] == p[i])
			{
				z = rot[j];
				write(1, &z, 1);
				c++;
				break;
			}
		}
		if (!real[j])
		{
			z = p[i];
			write(1, &z, 1);
			c++;
		}
	}
	return (c);
}



/**
 * printAddress - pointer variable
 * @type: input
 * @buffer: input
 * @flag: input
 * @width: input
 * @prec: input
 * @size: input
 * Return: int
 */
int printAddress(va_list type, char buffer[],
	int flag, int width, int prec, int size)
{
	char extra_c = 0, padding = ' ';
	int ex = BUFFER_SIZE - 2, len = 2, padding_start = 1;
	unsigned long numAddrs;
	char mapTo[] = "0123456789abcdef";
	void *address = va_arg(type, void *);

	NOT_USED(width);
	NOT_USED(prec);
	NOT_USED(size);

	if (address == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFFER_SIZE - 1] = '\0';

	numAddrs = (unsigned long)address;

	while (numAddrs > 0)
	{
		buffer[ex--] = mapTo[numAddrs % 16];
		numAddrs /= 16;
		len++;
	}

	if ((flag & ZERO) && !(flag & MINUS))
		padding = '0';
	if (flag & PLUS)
		extra_c = '+', len++;
	else if (flag & SPACE)
		extra_c = ' ', len++;

	ex++;
	return (printPointer(buffer, ex, len,
		width, flag, padding, extra_c, padding_start));
}
