#include "monty.h"

/**
 * f_rotl - rotates the stack to the top.
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void f_rotl(stack_t **head, unsigned int counter)
{
    stack_t *h, *first;

    (void)counter;

    if (!*head || !(*head)->next)
        return;

    h = *head;
    first = *head;
    *head = (*head)->next;
    (*head)->prev = NULL;

    while (h->next)
        h = h->next;

    h->next = first;
    first->prev = h;
    first->next = NULL;
}
