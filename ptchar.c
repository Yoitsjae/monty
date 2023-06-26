#include "monty.h"

/**
 * f_pchar - prints the char at the top of the stack.
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void f_pchar(stack_t **head, unsigned int counter)
{
    int ascii;

    if (!*head)
    {
        fprintf(stderr, "L%d: can't pchar, stack empty\n", counter);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }
    ascii = (*head)->n;
    if (ascii < 0 || ascii > 127)
    {
        fprintf(stderr, "L%d: can't pchar, value out of range\n", counter);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }
    putchar(ascii);
    putchar('\n');
}
