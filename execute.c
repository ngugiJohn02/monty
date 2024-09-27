#include "monty.h"

/**
 * execute - executes the opcode instructions
 * @opcode: the instruction to execute (e.g., "push", "pall")
 * @stack: pointer to the top of the stack
 * @line_number: line number in the file
 * @arg: argument for the opcode (e.g., the value for "push")
 *
 * Return: void
 */
void execute(char *opcode, stack_t **stack, unsigned int line_number, char *arg)
{
    if (strcmp(opcode, "push") == 0)
        push(stack, line_number, arg);
    else if (strcmp(opcode, "pall") == 0)
        pall(stack, line_number);
    else
    {
        fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
        exit(EXIT_FAILURE);
    }
}
