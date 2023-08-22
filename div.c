#include "monty.h"

/**
 * custom_div - Divides the top two elements of the stack.
 * @head: Pointer to the stack's head
 * @counter: Line number
 *
 * Return: No return value
 */
void custom_div(stack_t **head, unsigned int counter)
{
	stack_t *stack_ptr;
	int stack_size = 0, quotient;

	stack_ptr = *head;
	while (stack_ptr)
	{
		stack_ptr = stack_ptr->next;
		stack_size++;
	}
	if (stack_size < 2)
	{
		fprintf(stderr, "L%d: Unable to div, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		custom_free_stack(*head);
		exit(EXIT_FAILURE);
	}
	stack_ptr = *head;
	if (stack_ptr->n == 0)
	{
		fprintf(stderr, "L%d: Division by zero\n", counter);
		fclose(bus.file);
		free(bus.content);
		custom_free_stack(*head);
		exit(EXIT_FAILURE);
	}
	quotient = stack_ptr->next->n / stack_ptr->n;
	stack_ptr->next->n = quotient;
	*head = stack_ptr->next;
	free(stack_ptr);
}
