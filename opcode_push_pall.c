#include "monty.h"

/**
 * opcode_push - Pushes an element to the stack
 * @stack: Pointer to the top of the stack
 * @line_number: Line number in the Monty bytecode file
 */
void opcode_push(stack_t **stack, unsigned int line_number)
{
	char *arg = strtok(NULL, " \t\n");

	if (arg == NULL || !is_integer(arg))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	push(stack, atoi(arg));
}

/**
 * opcode_pall - Prints all the values on the stack
 * @stack: Pointer to the top of the stack
 * @line_number: Line number in the Monty bytecode file
 */
void opcode_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
