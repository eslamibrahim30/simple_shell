#include "main.h"

/**
 * create_path_list - Create a linked list of the PATH directories.
 * @list: the address of the list variable which will be assigned with
 * the new created linked list.
 *
 * Return: the address of the created list,
 * Or NULL if the function failed.
 */
list_t *create_path_list(list_t **list)
{
	char *name = "PATH";
	char *delim = ":";
	char *c_path = NULL;
	char *paths = NULL;
	list_t *ptr = NULL;

	paths = _getenv(name);
	c_path = strtok(paths, delim);
	while (1)
	{
		c_path = strtok(NULL, delim);
		if (c_path == NULL)
			break;
		ptr = add_node_end(list, c_path);
		if (ptr == NULL)
		{
			free_list(*list);
			return (NULL);
		}
	}
	return (*list);
}
