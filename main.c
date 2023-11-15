#include "shell.h"
#include <stdio.h>

/**
 * main - entry point of code
 *
 * Return: void
 */
int main(int c, char **argv, char **env)
{
	ssize_t num_chars;
	size_t size = 0;
	char *arg[15], *delim = " ";
	int i, j, waitstatus, exe;
	pid_t child_ID;
	char *prompt = "($) ";
	char *buffer = NULL;
	char *path;

	while (1)
	{
		/* print prompt amdtake input from user */
		if (isatty(0))
			_printstr(prompt);

		num_chars = getline(&buffer, &size, stdin);
		
		/* handle ctrl D (EOF) */
		if (num_chars == -1)
		{
			free(buffer);
			exit(0);
		}
		/* assign 0 to the last character which is the null terminator */
		if (buffer[num_chars - 1] == '\n')
			buffer[num_chars - 1] = '\0';

		/* tokenize user input */
		j = 0;
		arg[j]  = strtok(buffer, delim);

		while(arg[j])
		{
			arg[++j] = strtok(NULL, delim);
		}
		arg[j] = NULL;

		/* execute a given command */
		path = get_location(arg[0]);

		if (path == NULL)
		{
			if (handle_builtin(arg[0], arg) != 0)
			{
				perror("command not found");
				continue;
			}
		}
		else 
		{
			child_ID = fork();

			if (child_ID < 0)
			{
				perror("forking error");
				free(buffer);
				exit(0);
			}
			else if (child_ID == 0)
			{
				exe = execve(arg[0], arg, env);
				if (exe == -1)
					perror("Command does not exist");
			}

			if(waitpid(child_ID, &waitstatus, 0) == 0)
			{
				perror("Error occured (wait)");
				exit(0);
			}
		}
	}
	free(buffer);
	return (0);
}
