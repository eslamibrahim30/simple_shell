#include "main.h"

/**
 * is_accessable - Checks if the command exists or not.
 * @cmd: the given command.
 *
 * Return: 1 if it exists, 0 otherwise.
 */
int is_accessable(char **cmd)
{
	list_t *dirs = NULL;
	list_t *ptr = NULL;
	char path_buffer[BUFFER_MAX];
	int mode = F_OK | X_OK;

	if (cmd == NULL || *cmd == NULL)
	{
		return (0);
	}
	if (access(*cmd, mode) == 0)
	{
		return (1);
	}
	ptr = create_path_list(&dirs);
	if (ptr == NULL)
	{
		perror("./shell");
		return (0);
	}
	while (ptr != NULL)
	{
		strncpy(path_buffer, ptr->str, sizeof(path_buffer));
		strncat(path_buffer, "/", sizeof(path_buffer) - strlen(path_buffer) - 1);
		strncat(path_buffer, *cmd, sizeof(path_buffer) - strlen(path_buffer) - 1);
		if (access(path_buffer, mode) == 0)
		{
			*cmd = strdup(path_buffer);
			return (1);
		}
		ptr = ptr->next;
	}
	return (0);
}
