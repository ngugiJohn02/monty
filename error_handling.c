#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * file_open_error - Prints an error message for file opening errors
 * @filename: The name of the file that failed to open
 */
void file_open_error(const char *filename)
{
    fprintf(stderr, "Error: Can't open file %s\n", filename);
    exit(EXIT_FAILURE);
}

/**
 * usage_error - Prints the usage message for the Monty interpreter
 */
void usage_error(void)
{
    fprintf(stderr, "USAGE: monty file\n");
    exit(EXIT_FAILURE);
}

/**
 * invalid_instruction - Prints an error message for invalid instructions
 * @line_number: The line number where the error occurred
 * @opcode: The opcode that caused the error
 */
void invalid_instruction(unsigned int line_number, const char *opcode)
{
    fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
    exit(EXIT_FAILURE);
}

/**
 * invalid_push - Prints an error message for invalid push operations
 * @line_number: The line number where the error occurred
 */
void invalid_push(unsigned int line_number)
{
    fprintf(stderr, "L%u: usage: push integer\n", line_number);
    exit(EXIT_FAILURE);
}

/**
 * stack_empty_error - Prints an error message when trying to pint on an empty stack
 * @line_number: The line number where the error occurred
 */
void stack_empty_error(unsigned int line_number)
{
    fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
    exit(EXIT_FAILURE);
}

/**
 * malloc_error - Prints an error message for memory allocation failures
 */
void malloc_error(void)
{
    fprintf(stderr, "Error: malloc failed\n");
    exit(EXIT_FAILURE);
}

