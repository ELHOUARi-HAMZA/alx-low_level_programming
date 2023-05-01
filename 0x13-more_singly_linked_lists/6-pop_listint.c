#include "lists.h"

/**
 * pop_listint - Removes the head node of a linked list.
 * @head: Pointer to a pointer to the first element in the list.
 *
 * Return: The data inside the head node that was deleted, or 0 if the list is
 * empty.
 */
int pop_listint(listint_t **head)
{
	/* Declare a temporary pointer to hold the next node */
	listint_t *temp;
	int num;

	/* If the pointer to the head pointer is NULL, or the head pointer itself
	 * is NULL, return 0 to indicate an empty list. */
	if (!head || !*head)
		return (0);

	/* Store the data inside the head node */
	num = (*head)->n;

	/* Store the next node in the temporary pointer */
	temp = (*head)->next;

	/* Free the head node */
	free(*head);

	/* Set the head pointer to the next node */
	*head = temp;

	/* Return the data inside the deleted head node */
	return (num);
}
