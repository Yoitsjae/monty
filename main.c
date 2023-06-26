#include "monty.h"

/**
 * main - entry point for Monty interpreter
 * @argc: number of command-line arguments
 * @argv: array of command-line arguments
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */
int main(int argc, char **argv)
{
    FILE *file;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    stack_t *stack = NULL;
    unsigned int line_number = 0;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    bus.file = file;

    while ((read = getline(&line, &len, file)) != -1)
    {
        line_number++;
        execute(line, &stack, line_number);
    }

    free(line);
    fclose(file);
    free_stack(stack);
    return (EXIT_SUCCESS);
}
