#include "lists.h"

/**
 * print_listint - prints all the elements of a singly linked list
 * @h: pointer to the head of the list to print
 *
 * Return: the number of nodes in the list
 */
size_t print_listint(const listint_t *h)
{
    size_t num = 0;

    while (h)
    {
        printf("%d\n", h->n);
        num++;
        h = h->next;
    }

    return (num);
}
