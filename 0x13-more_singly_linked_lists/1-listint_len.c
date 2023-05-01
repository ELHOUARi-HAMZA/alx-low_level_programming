#include "lists.h"

/**
 * listint_len - returns the number of nodes in a singly linked list
 * @h: pointer to the head of the list to traverse
 *
 * Return: the number of nodes in the list
 */
size_t listint_len(const listint_t *h)
{
    size_t num = 0;

    while (h)
    {
        num++;
        h = h->next;
    }

    return (num);
}
