#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * main - Entry point for the Monty interpreter
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */
int main(int argc, char **argv)
{
    FILE *file;
    char line[1024];
    char *opcode;
    stack_t *stack = NULL;  // Initialize the stack
    unsigned int line_number = 0;

    // Check for proper number of arguments
    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    // Open the file
    file = fopen(argv[1], "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    // Read the file line by line
    while (fgets(line, sizeof(line), file))
    {
        line_number++;
        opcode = strtok(line, " \n\t");  // Tokenize the line to get the opcode

        // Skip empty lines
        if (opcode == NULL || *opcode == '#')
            continue;

        // Execute the corresponding opcode
        if (strcmp(opcode, "push") == 0)
        {
            // Get the next token as the argument for push
            char *arg = strtok(NULL, " \n\t");
            push(&stack, arg, line_number);
        }
        else if (strcmp(opcode, "pall") == 0)
        {
            pall(&stack);
        }
        else if (strcmp(opcode, "pint") == 0)
        {
            pint(&stack, line_number);
        }
        else
        {
            fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
            free_stack(stack);  // Free the stack memory if an error occ
	    fclose(file);
exit(EXIT_FAILURE);
}
}

// Cleanup and close the file
fclose(file);
free_stack(stack);  // Free the stack memory
return (EXIT_SUCCESS);
}

