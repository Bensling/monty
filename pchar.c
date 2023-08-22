#include "monty.h"

/**
 * custom_pchar - Prints the char at the top of the stack,
 *                followed by a new line.
 * @stack_head: Pointer to the stack's head
 * @line_num: Line number
 *
 * Return: No return value
 */
void custom_pchar(stack_t **stack_head, unsigned int line_num)
{
	stack_t *stack_ptr;

	stack_ptr = *stack_head;
	if (!stack_ptr)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_num);
		fclose(bus.file);
		free(bus.content);
		custom_free_stack(*stack_head);
		exit(EXIT_FAILURE);
	}
	if (stack_ptr->n > 127 || stack_ptr->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_num);
		fclose(bus.file);
		free(bus.content);
		custom_free_stack(*stack_head);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", stack_ptr->n);
}
