#include "monty.h"

/**
 * pall - prints all values on the stack
 * @stack: pointer to the top of the stack
 * @line_number: current line number (unused)
 *
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_number)
{
    stack_t *current = *stack;

    (void)line_number;  // Unused

    while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}
