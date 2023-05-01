#include "lists.h"

/**
 * sum_listint - Computes the sum of all the integers stored in a listint_t list.
 * @head: Pointer to the first node in the linked list.
 *
 * Return: The sum of all the integers in the list. If the list is empty, returns 0.
 */
int sum_listint(listint_t *head)
{
	int sum = 0;
	listint_t *temp = head;

	while (temp)
	{
		sum += temp->n;
		temp = temp->next;
	}

	return (sum);
}
