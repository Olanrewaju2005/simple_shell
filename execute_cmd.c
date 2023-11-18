#include "shell.h"
/**
  *execute_cmd - executes command found in path
  *@pathname: path of command entered by user
  *@argv: argument vector
  *@env: environment variable
  *
  *Return: void
  */
void execute_cmd(const char *pathname, char *const argv[], char *const env[])
{
	int waitstatus, exe;
	pid_t child_ID;

	child_ID = fork();

	if (child_ID < 0)
	{
		perror("forking error");
		exit(0);
	}
	else if (child_ID == 0)
	{
		exe = execve(pathname, argv, env);
		if (exe == -1)
			perror("Command does not exist");
	}
	else
		wait(&waitstatus);
}
