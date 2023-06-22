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
