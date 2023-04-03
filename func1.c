#include "main.h"




/**
 * printBinary - unsigned number
 * @type: input
 * @buffer: input
 * @flag: input
 * @width: input
 * @prec: input
 * @size: input
 * Return: int
 */
int printBinary(va_list type, char buffer[],
	int flag, int width, int prec, int size)
{
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int count;

	NOT_USED(buffer);
	NOT_USED(flag);
	NOT_USED(width);
	NOT_USED(prec);
	NOT_USED(size);

	n = va_arg(type, unsigned int);
	m = 2147483648;
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}


/**
 * printString - string
 * @type: input
 * @buffer: input
 * @flag:  input
 * @width: input
 * @prec: input
 * @size: input
 * Return: int
 */
int printString(va_list type, char buffer[],
	int flag, int width, int prec, int size)
{
	int len = 0, i;
	char *p = va_arg(type, char *);

	NOT_USED(buffer);
	NOT_USED(flag);
	NOT_USED(width);
	NOT_USED(prec);
	NOT_USED(size);
	if (p == NULL)
	{
		p = "(null)";
		if (prec >= 6)
			p = "      ";
	}
	while (p[len] != '\0')
		len++;
	if (prec >= 0 && prec < len)
		len = prec;

	if (width > len)
	{
		if (flag & MINUS)
		{
			write(1, &p[0], len);
			for (i = width - len; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - len; i > 0; i--)
				write(1, " ", 1);
			write(1, &p[0], len);
			return (width);
		}
	}
	return (write(1, p, len));
}
/**
 * printPercent - percent sign
 * Return: int
 */
int printPercent(void)
{
	return (write(1, "%%", 1));
}

/**
 * printInt - int
 * @type: input
 * @buffer: input
 * @flag: input
 * @width: input
 * @prec: input
 * @size: input
 * Return: int
 */
int printInt(va_list type, char buffer[],
	int flag, int width, int prec, int size)
{
	int i = BUFFER_SIZE - 2;
	int isNegative = 0;
	long int num = va_arg(type, long int);
	unsigned long int number;

	num = conv_sizeNumber(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFFER_SIZE - 1] = '\0';
	number = (unsigned long int)num;

	if (num < 0)
	{
		number = (unsigned long int)((-1) * num);
		isNegative = 1;
	}
	while (number > 0)
	{
		buffer[i--] = (number % 10) + '0';
		number /= 10;
	}
	i++;
	return (printNumber(isNegative, i, buffer, flag, width, prec, size));
}



/**
 * print_Char - char
 * @type: input
 * @buffer: input
 * @flag: input
 * @width: input
 * @prec: input
 * @size: input
 * Return: int
 */
int print_Char(va_list type, char buffer[],
	int flag, int width, int prec, int size)
{
	char ch = va_arg(type, int);

	return (printChar(ch, buffer, flag, width, prec, size));
}
