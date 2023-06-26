#include "monty.h"

/**
 * f_add - adds the top two elements of the stack.
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void f_add(stack_t **head, unsigned int counter)
{
    stack_t *tmp;

    if (!*head || !(*head)->next)
    {
        fprintf(stderr, "L%d: can't add, stack too short\n", counter);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    (*head)->next->n += (*head)->n;
    tmp = *head;
    *head = (*head)->next;
    (*head)->prev = NULL;
    free(tmp);
}
