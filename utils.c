#include "monty.h"

/**
 * is_integer - checks if a string represents a valid integer
 * @str: the string to check
 *
 * Return: 1 if it's a valid integer, 0 otherwise
 */
int is_integer(char *str)
{
    if (str == NULL || *str == '\0')
        return 0;

    if (*str == '-' || *str == '+')
        str++;

    while (*str)
    {
        if (*str < '0' || *str > '9')
            return 0;
        str++;
    }
    return 1;
}
