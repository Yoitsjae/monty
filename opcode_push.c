#include "monty.h"

/**
 * f_push - pushes an element to the stack.
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void f_push(stack_t **head, unsigned int counter)
{
    stack_t *new_node;
    char *arg = bus.arg;

    if (!arg || !is_number(arg))
    {
        fprintf(stderr, "L%d: usage: push integer\n", counter);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }
    new_node = malloc(sizeof(stack_t));
    if (!new_node)
    {
        fprintf(stderr, "Error: malloc failed\n");
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }
    new_node->n = atoi(arg);
    new_node->prev = NULL;
    if (!*head)
    {
        new_node->next = NULL;
    }
    else
    {
        new_node->next = *head;
        (*head)->prev = new_node;
    }
    *head = new_node;
}
