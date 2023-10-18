#include "shell.h"

/**
 * execute_command - Executes the command given.
 * @args: An array of pointers to the command and its arguments.
 *
 * Return: 1 on success, 0 on failure.
 */
int execute_command(char **args)
{
	pid_t pid;
	pid_t wpid;
	int status;

	(void)wpid;

	pid = fork();
	if (pid == 0)
	{
		if (execve(args[0], args, NULL) == -1)
		{
			perror(NULL);
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror(NULL);
	}
	else
	{
		do {
			wpid = waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (1);
}
