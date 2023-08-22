#include "monty.h"

/**
 * custom_mod - Calculates the remainder of the division of the second
 *              top element of the stack by the top element of the stack.
 * @stack_head: Pointer to the stack's head
 * @line_num: Line number
 *
 * Return: No return value
 */
void custom_mod(stack_t **stack_head, unsigned int line_num)
{
	stack_t *stack_ptr;
	int stack_size = 0, remainder;

	stack_ptr = *stack_head;
	while (stack_ptr)
	{
		stack_ptr = stack_ptr->next;
		stack_size++;
	}
	if (stack_size < 2)
	{
		fprintf(stderr, "L%d: Insufficient elements for mod operation\n", line_num);
		fclose(bus.file);
		free(bus.content);
		custom_free_stack(*stack_head);
		exit(EXIT_FAILURE);
	}
	stack_ptr = *stack_head;
	if (stack_ptr->n == 0)
	{
		fprintf(stderr, "L%d: Division by zero is not allowed\n", line_num);
		fclose(bus.file);
		free(bus.content);
		custom_free_stack(*stack_head);
		exit(EXIT_FAILURE);
	}
	remainder = stack_ptr->next->n % stack_ptr->n;
	stack_ptr->next->n = remainder;
	*stack_head = stack_ptr->next;
	free(stack_ptr);
}
