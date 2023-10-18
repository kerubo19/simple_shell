#ifndef __SIMPLE_SHELL_H__
#define __SIMPLE_SHELL_H__
#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGS 64
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

/*__FUNCTION_PROTOTYPES*/
void show_prompt(void);
char *read_command(void);
char **parse_command(char *command);
int execute_command(char **args);
void free_memory(char **args);
#endif /*SIMPLE_SHELL_H*/
