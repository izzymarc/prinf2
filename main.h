#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

/* Buffer size for the custom printf function */
#define BUFF_SIZE 1024

/* Flag definitions for formatting */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* Size specifiers */
#define S_LONG 2
#define S_SHORT 1

/* Struct for format specifiers */
typedef struct fmt
{
    char fmt;
    int (*fn)(va_list, char[], int, int, int, int);
} fmt_t;

/* Function prototypes */
int _printf(const char *format, ...);
int alphaPrintRoutine(va_list types, char buffer[],
                      int flags, int width, int precision, int size);
int breadthAnalyser(const char *format, int *i, va_list list);
int flagInterpreter(const char *format, int *i);
int numericDispenseCode(va_list types, char buffer[],
                        int flags, int width, int precision, int size);
int outputConductor(va_list types, char buffer[],
                    int flags, int width, int precision, int size);
int preciseCalcModule(const char *format, int *i, va_list list);
int printfAuxiliaries(va_list types, char buffer[],
                      int flags, int width, int precision, int size);
int printOrchestrator(const char *format, int *i, va_list list, char buffer[],
                      int flags, int width, int precision, int size);
int sizeDecipherUnit(const char *format, int *i);
int stringEmitLogic(va_list types, char buffer[],
                    int flags, int width, int precision, int size);

/* Utility function prototypes */
int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);

long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);

#endif /* MAIN_H */
