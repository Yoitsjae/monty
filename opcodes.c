#include "monty.h"

/**
 * push - Pushes an element to the stack
 * @stack: Double pointer to the head of the stack
 * @value: Value to be pushed
 */
void push(stack_t **stack, int value)

{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)

	{
		/* Handle malloc failure */
		fprintf(stderr, "Error: malloc failed\n");
		/* You can also exit with status EXIT_FAILURE if desired */
		return;
	}

	new_node->n = value;
	new_node->next = *stack;
	*stack = new_node;
}

/**
 * pall - Prints all the values on the stack
 * @stack: Double pointer to the head of the stack
 */
void pall(stack_t **stack)

{
	stack_t *current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * pint - Prints the value at the top of the stack
 * @stack: Pointer to the top of the stack
 * @line_number: Line number of the opcode
 */
void pint(stack_t **stack, unsigned int line_number)

	{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
