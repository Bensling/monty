#include "monty.h"

/**
 * c_rotr - Rotates the stack to the bottom.
 * @stack_head: Pointer to the stack's head
 * @counter: Line number
 *
 * Return: No return value
 */
void c_rotr(stack_t **stack_head, __attribute__((unused)) unsigned int counter)
{
	stack_t *copy;

	copy = *stack_head;
	if (*stack_head == NULL || (*stack_head)->next == NULL)
	{
		return;
	}
	while (copy->next)
	{
		copy = copy->next;
	}
	copy->next = *stack_head;
	copy->prev->next = NULL;
	copy->prev = NULL;
	(*stack_head)->prev = copy;
	(*stack_head) = copy;
}
