#include "shell.h"
/**
  *ss_getenv - functions like the getenv libary function
  *@env_name: env varible to be fetched
  *
  *Return: value of env variable
  */
char *ss_getenv(char *env_name)
{
	extern char **environ;
	int i, len;
	char *var;

	len = _str_len(env_name);

	for (i = 0; environ[i] != NULL; i++)
	{
		var = environ[i];

		if (strncmp(var, env_name, len) == 0 && var[len] == '=')
		{
			return (var);
		}
	}
	return (NULL);
}
