#include "monty.h"

/**
 * c_pint - Prints the top element of the stack.
 * @stack_head: Pointer to the stack's head
 * @line_num: Line number
 *
 * Return: No return value
 */
void c_pint(stack_t **stack_head, unsigned int line_num)
{
	if (*stack_head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_num);
		fclose(bus.file);
		free(bus.content);
		custom_free_stack(*stack_head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack_head)->n);
}
