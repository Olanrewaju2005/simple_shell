#include "shell.h"
/**
  *_strcpy - copies the string pointed to by src
  *@dest: char type string
  *@src: char type string
  *Description: copy the string pointrd to by the pointer `src` to
  *the buffer pointed to by `dest`
  *Return: pointer to `dest`
  */
char *_strcpy(char *dest, char *src)
{
	int z = -1;

	do {
		z++;
		dest[z] = src[z];
	} while (src[z] != '\0');
	return (dest);
}

/**
  *_strcat - funtion concatenates two strings
  *@dest: destinaation string
  *@src: source string
  *Return: pointer to s1
  */
char *_strcat(char *dest, char *src)
{
	char *dest_temp = dest;

	if (!src)
		return (dest);

	while (*dest)
	{
		dest++;
	}

	while (*src)
	{
		*dest++ = *src++;
	}
	*dest = *src;
	return (dest_temp);

}

/**
  *_str_len - this function returns the length of a string
  *@str: string to be computed
  *Return: the length of the string
  */
int _str_len(char *str)
{
	int string_length = 0;

	if (!str)
		return (string_length);

	for (string_length = 0; str[string_length]; string_length++)
		;
	return (string_length);
}
