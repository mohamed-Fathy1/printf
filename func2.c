#include "main.h"



/**
 * printHexa - Prints a hexadecimal
 * @type: input
 * @mapTo: input
 * @buffer: input
 * @flag: input
 * @flag_ch: input
 * @width: input
 * @prec: input
 * @size: input
 * Return: int
 */
int printHexa(va_list type, char mapTo[], char buffer[],
	int flag, char flag_ch, int width, int prec, int size)
{
	unsigned long int n = va_arg(type, unsigned long int);
	unsigned long int initNum = n;
	int i = BUFFER_SIZE - 2;

	NOT_USED(width);

	n = conv_sizeUnsgnd(n, size);

	if (n == 0)
		buffer[i--] = '0';
	buffer[BUFFER_SIZE - 1] = '\0';
	while (n > 0)
	{
		buffer[i--] = mapTo[n % 16];
		n /= 16;
	}
	if (flag & HASH && initNum != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}
	i++;
	return (printUnsgnd(0, i, buffer, flag, width, prec, size));
}

/**
 * printOctal - octal notation
 * @type: input
 * @buffer: input
 * @flag:  input
 * @width: input
 * @prec: input
 * @size: input
 * Return: int
 */
int printOctal(va_list type, char buffer[],
	int flag, int width, int prec, int size)
{

	int i = BUFFER_SIZE - 2;
	unsigned long int n = va_arg(type, unsigned long int);
	unsigned long int initNum = n;

	NOT_USED(width);

	n = conv_sizeUnsgnd(n, size);

	if (n == 0)
		buffer[i--] = '0';
	buffer[BUFFER_SIZE - 1] = '\0';
	while (n > 0)
	{
		buffer[i--] = (n % 8) + '0';
		n /= 8;
	}

	if (flag & HASH && initNum != 0)
		buffer[i--] = '0';

	i++;
	return (printUnsgnd(0, i, buffer, flag, width, prec, size));
}



/**
 * print_hexaUpper - upper hexadecimal notation
 * @type: input
 * @buffer: input
 * @flag: input
 * @width: input
 * @prec: input
 * @size: input
 * Return: int
 */
int print_hexaUpper(va_list type, char buffer[],
	int flag, int width, int prec, int size)
{
	return (printHexa(type, "0123456789ABCDEF", buffer,
		flag, 'X', width, prec, size));
}


/**
 * printHexadecimal - hexadecimal notation
 * @type: input
 * @buffer: input
 * @flag: input
 * @width: input
 * @prec: input
 * @size: input
 * Return: int
 */
int printHexadecimal(va_list type, char buffer[],
	int flag, int width, int prec, int size)
{
	return (printHexa(type, "0123456789abcdef", buffer,
		flag, 'x', width, prec, size));
}


/**
 * printUnsigned - unsigned number
 * @type: input
 * @buffer: input
 * @flag: input
 * @width: input
 * @prec: input
 * @size: input
 * Return: int
 */
int printUnsigned(va_list type, char buffer[],
	int flag, int width, int prec, int size)
{
	int i = BUFFER_SIZE - 2;
	unsigned long int n = va_arg(type, unsigned long int);

	n = conv_sizeUnsgnd(n, size);

	if (n == 0)
		buffer[i--] = '0';
	buffer[BUFFER_SIZE - 1] = '\0';
	while (n > 0)
	{
		buffer[i--] = (n % 10) + '0';
		n /= 10;
	}

	i++;

	return (printUnsgnd(0, i, buffer, flag, width, prec, size));
}

