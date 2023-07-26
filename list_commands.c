#include "main.h"

/**
 * list_commands - Store commands in an array
 * @cmds: the given array.
 * @cmd: the given command to be splitted.
 */
void list_commands(char *cmds[BUFFER_MAX], char *cmd)
{
	unsigned int j = 0;

	cmds[j] = _strtok(cmd, ";");
		while (cmds[j] != NULL && j < BUFFER_MAX - 1)
			cmds[++j] = _strtok(NULL, ";");
}
