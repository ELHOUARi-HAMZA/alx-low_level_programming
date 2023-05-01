#include "lists.h"

/**
 * delete_nodeint_at_index - Deletes the node at the specified index in a
 * listint_t linked list.
 *
 * @head: Pointer to a pointer to the first node of the list.
 * @index: The index of the node to be deleted, where indexing starts at 0.
 *
 * Return: If the function is successful, 1 is returned. Otherwise, -1 is returned.
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *temp = *head;
	listint_t *current = NULL;
	unsigned int i = 0;

	if (*head == NULL)
		return (-1);

	if (index == 0)
	{
		*head = (*head)->next;
		free(temp);
		return (1);
	}

	while (i < index - 1)
	{
		if (!temp || !(temp->next))
			return (-1);
		temp = temp->next;
		i++;
	}


	current = temp->next;
	temp->next = current->next;
	free(current);

	return (1);
}
