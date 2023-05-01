#include "lists.h"

/**
 * free_listint2 - Frees a linked list.
 * @head: Pointer to a pointer to the head of the list.
 *
 * This function frees the memory allocated for each node in the linked list
 * pointed to by `*head`, including the head node. It also sets `*head` to
 * NULL, to prevent a dangling pointer.
 */
void free_listint2(listint_t **head)
{
	listint_t *temp;

	if (head == NULL)
		return;

	while (*head)
	{
		temp = (*head)->next;
		free(*head);
		*head = temp;
	}

	*head = NULL;
}
