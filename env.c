#include "shell.h"
/**
  *
  *
  *
  */
char *ss_getenv(const char *env_name)
{
	extern char **environ;
	int i, len;
	char *var;
	len = strlen(env_name);

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
