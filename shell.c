#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - Super Simple Shell.
 *
 * Return: Always 0.
 */
int main(void)
{
	char *line = NULL;
	char *command[] = {line, NULL};
	pid_t child_pid;
	size_t len = 0;
	ssize_t nread;

	while (1)
	{
		printf("#cisfun$ ");
		nread = getline(&line, &len, stdin);
		if (nread == -1)
			break;
		command[0] = strtok(line, "\n");
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("./shell");
			return (1);
		}
		if (child_pid == 0)
		{
			if (execve(command[0], command, NULL) == -1)
			{
				perror("./shell");
				return (1);
			}
		}
		else
		{
			wait(NULL);
		}
	}
	free(line);
	exit(EXIT_SUCCESS);
}
