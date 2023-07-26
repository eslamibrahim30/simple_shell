#include "main.h"

/**
 * main - Super Simple Shell.
 *
 * Return: Always 0.
 */
int main(void)
{
	char ex_ptr[5] = "exit", env_str[4] = "env";
	char *command[BUFFER_MAX], *list_cmds[BUFFER_MAX];
	char *line = NULL, *cmd = NULL;
	unsigned int i = 0, j = 0;
	size_t len = 0;
	ssize_t nread = 0;

	while (1)
	{
		if (isatty(fileno(stdin)))
			printf("($) ");
		nread = _getline(&line, &len, stdin);
		if (nread == EOF)
			break;
		cmd = _strtok(line, "#");
		line = cmd;
		cmd = _strtok(line, "\n");
		list_commands(list_cmds, cmd);
		for (j = 0; list_cmds[j] != NULL; j++)
		{
			i = 0;
			command[i] = _strtok(list_cmds[j], " ");
			while (command[i] != NULL && i < BUFFER_MAX - 1)
				command[++i] = _strtok(NULL, " ");
			if (_strcmp(ex_ptr, command[0]) == 0 && command[1] != NULL)
				_quit(_atoi(command[1]));
			else if (_strcmp(ex_ptr, command[0]) == 0 && command[1] == NULL)
				_quit(0);
			else if (_strcmp(env_str, line) == 0)
				_env();
			else if (is_accessable(&command[0]))
				handle_cmd(command);
			else if (command[0] != NULL)
				perror("./shell");
		}
	}
	free(line);
	exit(EXIT_SUCCESS);
}
