#include "shell.h"
/**
 * main - entry point of code
 *@c: argument count
 *@argv: argument vector
 *@env: environment
 * Return: void
 */
int main(int c, char **argv, char **env)
{
	ssize_t num_chars;
	size_t size = 0;
	int j;
	char *prompt = "($) ", *buffer = NULL, *input_tok, *path;
	char *full_path, *arg[MAX_INPUT_SIZE], *delim = " ";
	(void)c;
	(void)argv;

	while (1)
	{
		if (isatty(0))
			_printstr(prompt);

		num_chars = getline(&buffer, &size, stdin);
		if (num_chars == -1)
		{
			free(buffer);
			exit(0);
			_printstr("\n");
		}
		if (buffer[num_chars - 1] == '\n')
			buffer[num_chars - 1] = '\0';

		j = 0;
		input_tok = strtok(buffer, delim);
		while (input_tok != NULL && j < MAX_INPUT_SIZE - 1)
		{
			arg[j] = input_tok;
			j++;
			input_tok = strtok(NULL, delim);
		}
		arg[j] = NULL;

		full_path = check_in_path(arg[0]);
		if (full_path != NULL)
		{
			execute_cmd(full_path, arg, env);
			continue;
		}
		else
		{
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
				execute_cmd(path, arg, env);
			}
		}
	}
	free(buffer);
	return (0);
}
