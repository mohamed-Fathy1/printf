#include "main.h"

/**
 * print_integar - function
 * @ap: input
 * @lenght: input
 */
void print_integar(va_list ap, int **lenght)
{
	char *p;
	int integar;
	int len = 0;

	integar = va_arg(ap, int);
	p = malloc(BUFF_SIZE);
	p = _inttoString(p, integar);
	len = strlen(p);
	**lenght += (len - 1);
	write(1, p, len);
	free(p);
}

/**
 * print_string - function
 * @ap: input
 * @lenght: input
 */
void print_string(va_list ap, int **lenght)
{
	int len = 0;
	char *p;

	p = va_arg(ap, char *);
	if (p == NULL)
		p = "(null)";
	len = strlen(p);
	**lenght += (len - 1);
	write(1, p, len);
}


/**
 * print_char - function
 * @ap: input
 */
void print_char(va_list ap)
{
	char x;

	x = va_arg(ap, int);
	write(1, &x, 1);
}


/**
 * function - function
 * @format: input
 * @ap: input
 * @i: input
 * @j: input
 * @prsent_mod: input
 * @lenght: input
 */
void function(const char *format, va_list ap,
		int *i, int j, int *lenght, int *prsent_mod)
{
	*prsent_mod = 0;
	switch (format[(*i + j) + 1])
	{
		case 'c':
			print_char(ap);
			break;
		case 's':
			print_string(ap, &lenght);
			break;
		case 'i':
		case 'd':
			print_integar(ap, &lenght);
			break;
		case 'u':
			print_unsigned_int(ap, &lenght);
			break;
		case '%':
			write(1, "%", 1);
			break;
		case ' ':
			*prsent_mod = 1;
			break;
		default:
			write(1, &format[*i], 1);
			(*i)--;
			break;
	}
}

/**
 * _printf - function
 * @format: input
 * Return: int
 */
int _printf(const char *format, ...)
{
	va_list ap;
	int n, lenght = 0, i;

	if (!format)
	{
		return (-1);
	}

	n = strlen(format);
	va_start(ap, format);

	if (format)
	{
		for (i = 0; i < n; i++)
		{
			lenght++;
			if (format[i] == '%')
			{
				int prsent_mod = 1, j = 0;

				for (; prsent_mod ; j++)
				{
					function(format, ap, &i, j, &lenght, &prsent_mod);
				}
				i += j;
			}
			else
			{
				write(1, &format[i], 1);
			}
		}
	}
	va_end(ap);
	return (lenght);
}
