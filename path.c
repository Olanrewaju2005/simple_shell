#include "shell.h"
/**arg_location -
  *@path:
  *@arg:
  *
  *Return:
  */
char *arg_location(char *path, char *arg)
{
	char *path_cpy, *path_tok, *file_path;
	char *delim = ":";

	path_cpy = strdup(path);
	path_tok = strtok(path_cpy, delim);
	file_path = malloc(_str_len(arg) + _str_len(path_tok) + 2);

	while (path_tok != NULL)
	{
		_strcpy(file_path, path_tok);
		_strcat(file_path, "/");
		_strcat(file_path, arg);
		_strcat(file_path, "\0");

		if(access(file_path, X_OK) == 0)
			return (strdup(file_path));

		path_tok = strtok(NULL, delim);
	}
	free(file_path);
	free(path_cpy);
	return (NULL);
}

/**get_location -
  *@arg:
  *
  *Return:
  */
char *get_location(char *arg)
{
	char *path;
	char *path_ex;
	path = getenv("PATH");

	if (path)
	{
		path_ex = arg_location(path, arg);
		return (path_ex);
	}

	return (NULL);
}