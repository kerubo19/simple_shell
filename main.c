#include "shell.h"

/**
 * main - the main loop for our shell project.
 *
 * Return: EXIT_SUCCESS on success
 */
int main(void)
{
	char *command;
	char **args;
	int status = 1;

	while (status)
	{
		show_prompt();
		command = read_command();
		/**
		 * if (strcmp(command, "") == 0)
		*{
		*	free(command);
		*	break;
		*}
		*/
		args = parse_command(command);
		status = execute_command(args);

		free(command);
		free_memory(args);
	}

	return (EXIT_SUCCESS);
}
