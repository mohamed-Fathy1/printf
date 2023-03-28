#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <stdarg.h>
#include <limits.h>

#define BUFF_SIZE 1024


void print_unsigned_int(va_list ap, int **lenght);
int _printf(const char *format, ...);
char *_inttoString(char *p, int num);
char *_unsigedtoString(char *p, unsigned int num);
int _getAddrass(va_list ap);
int _getOctal(va_list ap);
int _getHex(va_list ap, char *upper);
int append_hexa_code(char ascii_code, char buffer[], int i);

#endif
