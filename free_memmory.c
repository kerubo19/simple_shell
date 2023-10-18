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
