#include "monty.h"

/**
 * f_pstr - prints the string starting at the top of the stack.
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void f_pstr(stack_t **head, unsigned int counter)
{
    stack_t *h = *head;
    int ascii;

    (void)counter;

    while (h && h->n > 0 && h->n <= 127)
    {
        ascii = h->n;
        if (ascii == 0)
            break;
        putchar(ascii);
        h = h->next;
    }
    putchar('\n');
}
