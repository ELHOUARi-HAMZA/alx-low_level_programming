#include "lists.h"

/**
 * free_listint - Frees a linked list.
 * @head: Pointer to the head of the list.
 *
 * This function traverses the linked list pointed to by `head` and frees the
 * memory allocated for each node, including the head node.
 */
void free_listint(listint_t *head)
{
	/* Declare a temporary pointer to hold the next node */
	listint_t *temp;

	/* Traverse the list, freeing each node */
	while (head)
	{
		/* Store the next node in the temporary pointer */
		temp = head->next;

		/* Free the current node */
		free(head);

		/* Move on to the next node */
		head = temp;
	}
}
