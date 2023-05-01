#include "lists.h"

/**
 * get_nodeint_at_index - Returns the node at a certain index in a linked list.
 * @head: Pointer to the first node in the linked list.
 * @index: Index of the node to return.
 *
 * Return: Pointer to the node at the specified index, or NULL if the index is
 * out of range.
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	/* Initialize a counter variable and a temporary pointer */
	unsigned int i = 0;
	listint_t *temp = head;

	/* Traverse the list until the specified index is reached */
	while (temp && i < index)
	{
		temp = temp->next;
		i++;
	}

	/* If the temporary pointer is not NULL, it points to the node at the
	 * specified index, so return it. Otherwise, return NULL. */
	return (temp ? temp : NULL);
}
