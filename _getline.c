#include "shell.h"

/**_realloc - 
  *@o_size:
  *@n_size:
  *
  *Return:
  */
void *_realloc(void *prev_alloc, ssize_t o_size, ssize_t n_size)
{
	void *n_alloc, *prev_alloccpy = prev_alloc;
	unsigned int i;
	char *charprev_alloccpy = (char *) prev_alloccpy;
	char *charmemory_fill = (char *) prev_alloccpy;

	if (o_size == n_size)
		return (prev_alloc);

	if (n_size == 0 && o_size != 0)
	{
		free(prev_alloc);
		return (NULL);
	}

	if (prev_alloc == NULL && n_size != 0)
	{
		n_alloc = malloc(n_size);
		if (n_alloc == NULL)
			return (NULL); /* memory allocation failed */

		return (n_alloc);
	}

	prev_alloccpy = prev_alloc;
	n_alloc = malloc(sizeof(char *) * n_size);

	if (n_alloc == NULL)
	{
		free(prev_alloc);
		return (NULL);
	}

	for (i = 0; i < o_size && i < n_size; i++)
		charmemory_fill[i] = charprev_alloccpy[i];

	free(prev_alloc);
	return (n_alloc);
	
}

/**update_line_size -
  *@lineptr:
  *@size:
  *@buffer:
  *@buffsize:
  *
  *Return:
  */
void update_line_size(char **lineptr, size_t *size, char *buffer, size_t buffsize)
{
	if (*lineptr == NULL)
	{
		if (buffsize > 120)
			*size = buffsize;
		else
			*size = 120;
		*lineptr = buffer;
	}
	else if (*size < buffsize)
	{
		if (buffsize > 120)
			*size = buffsize;
		else
			*size = 120;
		*lineptr = buffer;
	}
	else
	{
		strcpy(*lineptr, buffer);
		free(buffer);
	}
}

/**_getline - function gets input entered by user and stores it in  a buffer
  *@lineptr: stores address of buffer containing the text
  *@size: size of line to  be read
  *@stream: stream to be read from i.e STDIN or STDOUT
  *
  *Return: number of characters read are returned o success and -1 on faliure
 */
ssize_t _getline(char **lineptr, size_t *size)
{
	ssize_t n_char;
	static ssize_t count;
	static char *buffer;
	char ch;
	int r;
	ch = **lineptr;
	count = 0;

	printf("%d", ch);

	buffer = malloc(sizeof(char *) * 120);
	if (!buffer)
		return (-1); /* malloc failed */

	while (ch != '\0')
	{
	r = read(STDIN_FILENO, &ch, 1);
	if (r == -1 || (r == 0 && count == 0))
	{
		free(buffer);
		return (-1);
	}
	if (r == 0 && count != 0)
	{
		count++;
		break;
	}
	if (count >= 120)
		buffer = _realloc(&buffer, count, count + 1);

	buffer[count] = ch;
	count++;
	}
	
	buffer[count + 1] = '\0';

	update_line_size(lineptr, size, buffer, count);
	n_char = count;

	return (n_char);
}
