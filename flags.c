#include "main.h"

/**
 * getFlags - flags
 * @fmt: input
 * @index: input
 * Return: int
 */
int getFlags(const char *fmt, int *index)
{
	int j, curr_i, flag = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {MINUS, PLUS, ZERO, HASH, SPACE, 0};

	for (curr_i = *index + 1; fmt[curr_i] != '\0'; curr_i++)
	{
		for (j = 0; FLAGS_CH[j] != '\0'; j++)
			if (fmt[curr_i] == FLAGS_CH[j])
			{
				flag |= FLAGS_ARR[j];
				break;
			}

		if (FLAGS_CH[j] == 0)
			break;
	}

	*index = curr_i - 1;

	return (flag);
}

