#include "shell.h"

/**
 * free_memory - Free the allocated memory for the tokens.
 * @args: An array of pointers to the tokens.
 */
void free_memory(char **args)
{
	/*size_t i;*/

	/**
	 * for (i = 0; args[i] != NULL; i++)
	*{
	*	free(args[i]);
	*}
	*/
	free(args);
}

/**
 * handle_builtin_command - Handles built-in commands
 * @args: An array of pointers to the command and its arguments.
 *
 * Return: 1 on success, 0on fail
 */
int handle_builtin_command(char **args)
{
	int status;

	if (args == NULL || args[0] == NULL)
	{
		return (1);
	}
	if (strcmp(args[0], "exit") == 0)
	{
		if (args[1] != NULL)
		{
			status = atoi(args[1]);
			exit(status);
		}
		else
		{
			exit(EXIT_SUCCESS);
		}
	}
	else if (strcmp(args[0], "env") == 0)
	{
		print_environment();
		return (1);
	}
	return (0);
}
/**
 * print_environment - Prints the current environment
 */
void print_environment(void)
{
	char **env = environ;
	int i = 0;
	size_t len;
	(void)i;

	while (*env)
	{
		len = strlen(*env);
		write(STDOUT_FILENO, *env, len);
		write(STDOUT_FILENO, "\n", 1);
		env++;
	}
}
