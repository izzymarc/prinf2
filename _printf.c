
#include "main.h"

/*
 * _printf - Custom implementation of the printf function
 * @format: Format string containing the characters and format specifiers
 * 
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	/* Counter for the number of characters printed */
	int count = 0;
	/* To handle the variable number of arguments */
	va_list args;
	/* Loop index for iterating through the format string */
	int i = 0;
	/* Temporary character for `%c` */
	char ch;
	/* Temporary string for `%s` */
	char *str;

	/* Start processing the variable arguments */
	va_start(args, format);

	/* Iterate through the format string */
	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++; /* Move to the next character for specifier */
			switch (format[i])
			{
				case 'c': /* Character */
					ch = (char)va_arg(args, int); /* Fetch char argument */
					putchar(ch); /* Print the character */
					count++; /* Increment count */
					break;

				case 's': /* String */
					str = va_arg(args, char*); /* Fetch string argument */
					while (*str) /* Print each character of the string */
					{
						putchar(*str);
						str++;
						count++;
					}
					break;

				case '%': /* Percent sign */
					putchar('%'); /* Print the percent sign */
					count++; /* Increment count */
					break;

				default: /* Unsupported specifiers */
					/* You can handle unsupported specifiers here */
					break;
			}
		}
		else /* Regular character */
		{
			putchar(format[i]); /* Print the regular character */
			count++; /* Increment count */
		}
		i++; /* Move to the next character in the format string */
	}

	/* Clean up */
	va_end(args);

	return count; /* Return the number of characters printed */
}
