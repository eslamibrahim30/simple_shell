#include "main.h"

/**
 * add_node_end - Adds a new node at the end of a list_t list
 * @head: the address of the head of the list
 * @str: the value of the new node
 *
 * Return: the address of the new element, or NULL if it failed
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *node;
	list_t *itr;

	node = (list_t *)malloc(sizeof(list_t));
	if (node == NULL)
		return (NULL);
	node->str = strdup(str);
	node->next = NULL;
	itr = *head;
	if (itr == NULL)
	{
		*head = node;
	}
	else
	{
		while (itr->next != NULL)
			itr = itr->next;
		itr->next = node;
	}
	return (node);
}


/**
 * free_list - Frees a list_t list.
 * @head: the address of the head of the list
 */
void free_list(list_t *head)
{
	if (head == NULL)
		return;
	if (head->next == NULL)
	{
		free(head->str);
		free(head);
		return;
	}
	free_list(head->next);
	free(head->str);
	free(head);
}
