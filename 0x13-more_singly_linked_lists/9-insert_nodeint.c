#include "lists.h"

/**
 * insert_nodeint_at_index - Inserts a new node containing the given data into
 * the specified position in a listint_t linked list.
 *
 * @head: Pointer to a pointer to the first node of the list.
 * @idx: The index of the new node to be added, where indexing starts at 0.
 * @n: The data to be stored in the new node.
 *
 * Return: If the function is successful, a pointer to the new node is returned.
 * Otherwise, NULL is returned.
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int i;
	listint_t *new;
	listint_t *temp = *head;

	new = malloc(sizeof(listint_t));
	if (!new || !head)
		return (NULL);

	new->n = n;
	new->next = NULL;

	if (idx == 0)
	{
		new->next = *head;
		*head = new;
		return (new);
	}

	for (i = 0; temp && i < idx; i++)
	{
		if (i == idx - 1)
		{
			new->next = temp->next;
			temp->next = new;
			return (new);
		}
		else
			temp = temp->next;
	}

	return (NULL);
}
