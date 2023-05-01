#include "lists.h"

/**
 * add_nodeint - adds a new node at the beginning of a singly linked list
 * @head: double pointer to the head of the list
 * @n: value to be added to the new node
 *
 * Return: pointer to the new node, or NULL on failure
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
    listint_t *new;

    new = malloc(sizeof(listint_t));
    if (!new)
        return (NULL);

    new->n = n;
    new->next = *head;
    *head = new;

    return (new);
}
