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
	/* Declare a temporary pointer to hold the next node */
	listint_t *temp;

	/* If the pointer to the head pointer is NULL, return */
	if (head == NULL)
		return;

	/* Traverse the list, freeing each node */
	while (*head)
	{
		/* Store the next node in the temporary pointer */
		temp = (*head)->next;

		/* Free the current node */
		free(*head);

		/* Move on to the next node */
		*head = temp;
	}

	/* Set the head pointer to NULL, to prevent a dangling pointer */
	*head = NULL;
}
