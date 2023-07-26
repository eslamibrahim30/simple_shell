#include "main.h"

/**
 * handle_cmd - Handles the execution of a given command.
 * @command: the array of strings which contains the command.
 */
void handle_cmd(char *command[BUFFER_MAX])
{
	pid_t child_pid = 0;

	child_pid = fork();
	if (child_pid == -1)
		perror("./shell");
	if (child_pid == 0)
	{
		if (execve(command[0], command, environ) == -1)
			perror("./shell");
	}
	else
		wait(NULL);
}
