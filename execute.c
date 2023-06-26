#include "monty.h"

/**
 * execute - executes the corresponding opcode.
 * @opcode: opcode
 * @stack: pointer to the stack
 * @line_number: line number
 * Return: no return
 */
void execute(char *opcode, stack_t **stack, unsigned int line_number)
{
    int i = 0;

    instruction_t opcodes[] = {
        {"push", f_push},
        {"pall", f_pall},
        {"pint", f_pint},
        {"pop", f_pop},
        {"swap", f_swap},
        {"add", f_add},
        {"nop", f_nop},
        {NULL, NULL}
    };

    while (opcodes[i].opcode)
    {
        if (strcmp(opcode, opcodes[i].opcode) == 0)
        {
            opcodes[i].f(stack, line_number);
            return;
        }
        i++;
    }

    fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
    fclose(bus.file);
    free(bus.content);
    free_stack(*stack);
    exit(EXIT_FAILURE);
}
