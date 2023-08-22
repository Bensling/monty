#include "monty.h"

/**
 * c_pop - Removes the top element from the stack.
 * @stack_head: Pointer to the stack's head
 * @line_num: Line number
 *
 * Return: No return value
 */
void c_pop(stack_t **stack_head, unsigned int line_num)
{
	stack_t *stack_ptr;

	if (*stack_head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_num);
		fclose(bus.file);
		free(bus.content);
		custom_free_stack(*stack_head);
		exit(EXIT_FAILURE);
	}
	stack_ptr = *stack_head;
	*stack_head = stack_ptr->next;
	free(stack_ptr);
}

