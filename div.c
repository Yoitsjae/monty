#include "monty.h"

/**
 * f_div - divides the second top element of the stack by the top element.
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void f_div(stack_t **head, unsigned int counter)
{
    stack_t *tmp;

    if (!*head || !(*head)->next)
    {
        fprintf(stderr, "L%d: can't div, stack too short\n", counter);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    if ((*head)->n == 0)
    {
        fprintf(stderr, "L%d: division by zero\n", counter);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    (*head)->next->n /= (*head)->n;
    tmp = *head;
    *head = (*head)->next;
    (*head)->prev = NULL;
    free(tmp);
}
