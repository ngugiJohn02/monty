#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * push - Pushes an integer onto the stack
 * @stack: Double pointer to the stack
 * @arg: The argument passed with the push command
 * @line_number: The current line number in the bytecode file
 */
void push(stack_t **stack, char *arg, unsigned int line_number)
{
    int n;

    // Validate the argument
    if (arg == NULL || !is_integer(arg))
    {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    n = atoi(arg);  // Convert string to integer

    // Create a new stack node
    stack_t *new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = n;
    new_node->prev = NULL;
    new_node->next = *stack;

    // Link the new node to the stack
    if (*stack != NULL)
        (*stack)->prev = new_node;

    *stack = new_node;  // Update the stack head
}

/**
 * pall - Prints all values on the stack
 * @stack: Double pointer to the stack
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

/**
 * pint - Prints the value at the top of the stack
 * @stack: Double pointer to the stack
 * @line_number: The current line number in the bytecode file
 */
void pint(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL)
    {
        fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }
    printf("%d\n", (*stack)->n);
}

/**
 * is_integer - Checks if a string is a valid integer
 * @s: The string to check
 *
 * Return: 1 if the string is a valid integer, 0 otherwise
 */
int is_integer(char *s)
{
    if (*s == '-' || *s == '+')
        s++;

    while (*s)
    {
        if (*s < '0' || *s > '9')
            return 0;
        s++;
    }
    return 1;
}

