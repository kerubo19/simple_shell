#include "shell.h"

/**
 * read_command - Read a command from the standard input..
 *
 * Return: The command read from the user input.
 */
char *read_command(void)
{
	char *command = NULL;
	size_t bufsize = 0;

	if (getline(&command, &bufsize, stdin) == -1)
	{
		if (feof(stdin))
		{
			free(command);
			_exit(EXIT_SUCCESS);
		}
		perror("read_command");
		exit(EXIT_FAILURE);
	}
	return (command);
}

/**
 * parse_command - Parse the command in the tokens.
 * @command: The command to be parsed.
 *
 * Return: An array of pointers to the tokens.
 */
char **parse_command(char *command)
{
	int bufsize = 64, position = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token;

	if (!tokens)
	{
		perror("parse_command");
		exit(EXIT_FAILURE);
	}
	token = strtok(command, " \t\r\n\a");
	while (token != NULL)
	{
		tokens[position] = token;
		position++;
		if (position >= bufsize)
		{
			bufsize += 64;
			tokens = realloc(tokens, bufsize * sizeof(char *));
			if (!tokens)
			{
				perror("parse_command");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, " \t\r\n\a");
	}
	tokens[position] = NULL;
	return (tokens);
}
