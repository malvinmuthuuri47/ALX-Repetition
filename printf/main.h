#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/* structs */
typedef struct
{
	int plus;
	int space;
	int hash;
} format_flags;

/* Buffer Utils */
static void flush_buffer(char *buffer, int *idx);
static void buffer_putchar(char c, char *buffer,
		int *idx, int buf_size, int *total);
static void buffer_puts(const char *s, char *buffer,
		int *idx, int buf_size, int *total);

/* String utils */
static int my_strlen(const char *s);

/* Converters */
static char *my_itoa(int n);
static void my_putbin(unsigned int num, char *buffer, int *idx,
		int buf_size, int *total);
static char *my_utoa(unsigned int num, int base, int uppercase);
static char *my_ultoa_base(unsigned long num, int base, int uppercase);

/* Flags */
static const char *parse_flags(const char *fmt, format_flags *flags);

/* Specifier Handler */
static void handle_specifier(char spec, va_list args, char *buffer,
		int *idx, int buf_size, int *total, format_flags flags);

/* Main Print */
int _printf(const char *format, ...);

#endif
