#include "shell.h"

/**
 * _printstr - prints output
 * @text: the output to print
 * Return: void
 */
int _printstr(char *text)
{
	int i = 0, count = 0;

	while (text[i])
	{
		count += _putchar(text[i++]);
	}
	return (count);
}

/**
  *_putchar - prints an entry to standard output
  *@c: character to be printed
  *
  *Return: 0 on succes
  */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
