#include "monty.h"

/**
 * custom_swap - Swaps the top two elements of the stack.
 * @stack_head: Pointer to the stack's head
 * @line_num: Line number
 *
 * Return: No return value
 */
void custom_swap(stack_t **stack_head, unsigned int line_num)
{
	stack_t *stack_ptr;
	int len = 0, temp;

	stack_ptr = *stack_head;
	while (stack_ptr)
	{
		stack_ptr = stack_ptr->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: Unable to swap, stack too short\n", line_num);
		fclose(bus.file);
		free(bus.content);
		custom_free_stack(*stack_head);
		exit(EXIT_FAILURE);
	}
	stack_ptr = *stack_head;
	temp = stack_ptr->n;
	stack_ptr->n = stack_ptr->next->n;
	stack_ptr->next->n = temp;
}
