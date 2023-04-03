#include "main.h"

/**
 * appendHexaCode - hexadecimal code to buffer
 * @buffer: input
 * @j: input
 * @asciiCode: input
 * Return: int
 */
int appendHexaCode(char asciiCode, char buffer[], int j)
{
	char mapto[] = "0123456789ABCDEF";

	if (asciiCode < 0)
		asciiCode *= -1;
	buffer[j++] = '\\';
	buffer[j++] = 'x';
	buffer[j++] = mapto[asciiCode / 16];
	buffer[j] = mapto[asciiCode % 16];
	return (3);
}

/**
 * isDigit - is a digit
 * @character: input
 * Return: int
 */
int isDigit(char character)
{
	if (character >= '0' && character <= '9')
		return (1);
	return (0);
}


/**
 * conv_sizeUnsgnd - specified size
 * @n: input
 * @size: input
 * Return: long int
 */
long int conv_sizeUnsgnd(unsigned long int n, int size)
{
	if (size == LONG)
		return (n);
	else if (size == SHORT)
		return ((unsigned short)n);
	return ((unsigned int)n);
}

/**
 * conv_sizeNumber - specified size
 * @n: input
 * @size: input
 * Return: long int
 */
long int conv_sizeNumber(long int n, int size)
{
	if (size == LONG)
		return (n);
	else if (size == SHORT)
		return ((short)n);
	return ((int)n);
}


/**
 * isPrintable - char is printable
 * @character: input
 * Return: input
 */
int isPrintable(char character)
{
	if (character >= 32 && character < 127)
		return (1);
	return (0);
}
