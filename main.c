#include "monty.h"

int main(void)
{
	stack_t *stack = NULL;

	/* Example usage of push and pall */
	push(&stack, 1);
	push(&stack, 2);
	push(&stack, 3);
	pall(stack);

	return (EXIT_SUCCESS);
}
