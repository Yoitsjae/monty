#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Structure for the stack (or queue) */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/* Structure for opcodes */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* Opcode function prototypes */
void opcode_push(stack_t **stack, unsigned int line_number);
void opcode_pall(stack_t **stack, unsigned int line_number);

/* Utility function prototypes */
int is_integer(char *str);
void push(stack_t **stack, int value);

#endif /* MONTY_H */
