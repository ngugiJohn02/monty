#include <stdlib.h>
#include "monty.h"

/**
 * add_node - Adds a new node at the beginning of the stack
 * @stack: Double pointer to the stack
 * @value: The integer value for the new node
 * 
 * Return: Pointer to the new node, or NULL on failure
 */
stack_t *add_node(stack_t **stack, int value)
{
    stack_t *new_node = malloc(sizeof(stack_t));
    if (!new_node)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    new_node->n = value;
    new_node->next = *stack;
    new_node->prev = NULL;

    if (*stack != NULL)
        (*stack)->prev = new_node;

    *stack = new_node;

    return new_node;
}

/**
 * free_stack - Frees all nodes in the stack
 * @stack: Double pointer to the stack
 */
void free_stack(stack_t **stack)
{
    stack_t *current = *stack;
    stack_t *next_node;

    while (current != NULL)
    {
        next_node = current->next;
        free(current);
        current = next_node;
    }

    *stack = NULL;  // Set the stack pointer to NULL
}

/**
 * print_stack - Prints the entire stack for debugging purposes
 * @stack: The stack to print
 */
void print_stack(stack_t *stack)
{
    stack_t *current = stack;

    while (current != NULL)
    {
        printf("%d ", current->n);
        current = current->next;
    }
    printf("\n");
}

/**
 * stack_len - Calculates the length of the stack
 * @stack: The stack to measure
 * 
 * Return: The number of nodes in the stack
 */
size_t stack_len(stack_t *stack)
{
    size_t len = 0;
    stack_t *current = stack;

    while (current)
    {
        len++;
        current = current->next;
    }

    return len;
}

