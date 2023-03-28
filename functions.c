#include "main.h"


/**
 * print_unsigned_int - function
 * @ap: input
 * @lenght: input
 */
void print_unsigned_int(va_list ap, int **lenght)
{
	unsigned int unIntegar;
	int len;
	char *p;

	unIntegar = va_arg(ap, unsigned int);
	p = malloc(BUFF_SIZE);
	p = _unsigedtoString(p, unIntegar);
	len = strlen(p);
	**lenght += (len - 1);
	write(1, p, len);
	free(p);
}


/**
 * _unsigedtoString - function
 * @p: input
 * @num: input
 * Return: char *
 */
char *_unsigedtoString(char *p, unsigned int num)
{
	unsigned int i = 0, rem, len = 0, n;

	n = num;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	if (num == 0)
	{
		*p = '0';
		return (p);
	}
	for (; i < len; i++)
	{
		rem = num % 10;
		num = num / 10;
		p[len - (i + 1)] = rem + '0';
	}
	return (p);
}




/**
 * _inttoString - function
 * @p: input
 * @num: input
 * Return: char *
 */
char *_inttoString(char *p, int num)
{
	int i = 0, rem, len = 0, n, sub;
	unsigned int longINT;

	n = num;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	if (num == 0)
	{
		*p = '0';
		return (p);
	}
	sub = 0;
	if (num < 0)
	{
		sub = 1;
		p[0] = '-';
		len++;
		longINT = num * -1;
	}
	else
		longINT = num;
	for (; i < (len - sub); i++)
	{
		rem = longINT % 10;
		longINT = longINT / 10;
		p[len - (i + 1)] = rem + '0';
	}
	return (p);
}
