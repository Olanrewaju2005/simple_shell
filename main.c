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
	char *arg[MAX_INPUT_SIZE], *delim = " ";
	int j, waitstatus, exe;
	pid_t child_ID;
	char *prompt = "($) ";
	char *buffer = NULL;
	char *input_tok;
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
			_printstr("\n");
		}
		/* assign 0 to the last character which is the null terminator */
		if (buffer[num_chars - 1] == '\n')
			buffer[num_chars - 1] = '\0';

		/* tokenize user input */
		j = 0;
		input_tok = strtok(buffer, delim);

		while(input_tok != NULL && j < MAX_INPUT_SIZE -1)
		{
			arg[j] = input_tok;
			j++;
			input_tok = strtok(NULL, delim);
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
				exe = execve(path, arg, env);
				if (exe == -1)
					perror("Command does not exist");
			}
			else
				wait(&waitstatus);
		}
	}
	free(buffer);
	return (0);
}
