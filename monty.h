#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Structure for the doubly linked list (stack) */
typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

/* Structure for the opcode and its function */
typedef struct instruction_s
{
    char *opcode;
    void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* Function prototypes */
void push(stack_t **stack, unsigned int line_number, char *value);
void pall(stack_t **stack, unsigned int line_number);
void execute(char *opcode, stack_t **stack, unsigned int line_number, char *arg);
int is_integer(char *str);

/* Error handling functions can be declared here as needed */

#endif
