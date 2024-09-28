#define _POSIX_C_SOURCE 200809L
#include "monty.h"

/**
 * main - Entry point of the Monty interpreter
 * @argc: Argument count
 * @argv: Argument vector (contains the bytecode file)
 *
 * Return: 0 on success, or an error code on failure
 */
int main(int argc, char **argv)
{
    FILE *file;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    unsigned int line_number = 0;
    stack_t *stack = NULL;
    char *opcode, *arg;

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

    while ((read = getline(&line, &len, file)) != -1)
    {
        line_number++;
        opcode = strtok(line, " \n");
        arg = strtok(NULL, " \n");

        if (opcode == NULL || opcode[0] == '#')  // Ignore empty lines or comments
            continue;

        execute(opcode, &stack, line_number, arg);
    }

    free(line);
    fclose(file);
    // Free the stack here if needed
    return (0);
}
