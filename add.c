#include "monty.h"

/**
 * custom_add - Adds the top two elements of the stack.
 * @stack_head: Pointer to the stack's head
 * @line_num: Current line number
 *
 * Return: No return value
 */
void custom_add(stack_t **stack_head, unsigned int line_num)
{
	stack_t *stack_ptr;
	int stack_size = 0, sum;

	stack_ptr = *stack_head;
	while (stack_ptr)
	{
		stack_ptr = stack_ptr->next;
		stack_size++;
	}
	if (stack_size < 2)
	{
		fprintf(stderr, "Line %d: Unable to add, insufficient stack elements\n",
				line_num);
		fclose(bus.file);
		free(bus.content);
		custom_free_stack(*stack_head);
		exit(EXIT_FAILURE);
	}
	stack_ptr = *stack_head;
	sum = stack_ptr->n + stack_ptr->next->n;
	stack_ptr->next->n = sum;
	*stack_head = stack_ptr->next;
	free(stack_ptr);
}
