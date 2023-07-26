#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER_MAX 1024

extern char **environ;

/**
 * struct list_s - singly linked list
 * @str: string - (malloc'ed string)
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 */
typedef struct list_s
{
	char *str;
	struct list_s *next;
} list_t;


list_t *add_node_end(list_t **head, const char *str);
void free_list(list_t *head);
char *_getenv(const char *name);
list_t *create_path_list(list_t **list);
int is_accessable(char **cmd);
void _quit(int status);
void _env(void);
int _strcmp(char *s1, char *s2);
int _atoi(char *s);
char *_strtok(char *str, char *delim);
ssize_t _getline(char **line, size_t *len, FILE *stream);
void handle_cmd(char *command[BUFFER_MAX]);
void list_commands(char *cmds[BUFFER_MAX], char *cmd);

#endif
