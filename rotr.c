#include "monty.h"

/**
 * f_rotr - rotates the stack to the bottom.
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void f_rotr(stack_t **head, unsigned int counter)
{
    stack_t *h = *head;

    (void)counter;

    if (!*head || !(*head)->next)
        return;

    while (h->next)
        h = h->next;

    h->prev->next = NULL;
    h->next = *head;
    h->prev = NULL;
    (*head)->prev = h;
    *head = h;
}
