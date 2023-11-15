#include "shell.h"
/**hanlde_builtin -
  *
  *
  *Return:
  */
int handle_builtin(char *cmd, char *arg[])
{
	extern char **environ;

	if (strcmp(cmd, "cd") == 0)
	{
		if (arg[1] != NULL)
		{
			if (chdir(arg[1]))
				perror("Unknown error occured");
		}
		else
		{
			chdir(getenv("HOME"));
		}
	}
	else if (strcmp(cmd, "exit") == 0)
	{
		exit(0);
	}
	else if (strcmp(cmd, "env") == 0)
	{
		char **env = environ;
		size_t i;

		while (*env)
		{
			write(1, *env, i);
			i++;
		}
	}
	else
		return (-1);

	return (0);
}
