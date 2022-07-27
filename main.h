#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <stdarg.h>

extern char **environ;

int _strlen(char *s);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strdup(char *str);
int _strncmp(char *s1, char *s2, int n);
char **make_av(char *);
int execute(char **command);


/*printf*/
int _printf(const char *format, ...);
int (*get_func(char conv_spec))(va_list, int);
int print_char(va_list ap, int count);
int print_str(va_list ap, int count);
int stringlength(char *str);
int _putchar(char c);
int print_dec(va_list ap, int count);
int dec_print(int c);
int int_len(int c);
int _putchar(char c);

typedef struct type
{
	char form_match;
	int (*func)(va_list, int);
} type_t;

#endif/*MAIN_H*/
