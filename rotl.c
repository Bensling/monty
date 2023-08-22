#include "monty.h"

/**
 * c_rotl - Rotates the stack to the top.
 * @stack_head: Pointer to the stack's head
 * @counter: Line number
 *
 * Return: No return value
 */
void c_rotl(stack_t **stack_head, __attribute__((unused)) unsigned int counter)
{
	stack_t *tmp = *stack_head, *aux;

	if (*stack_head == NULL || (*stack_head)->next == NULL)
	{
		return;
	}
	aux = (*stack_head)->next;
	aux->prev = NULL;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = *stack_head;
	(*stack_head)->next = NULL;
	(*stack_head)->prev = tmp;
	(*stack_head) = aux;
}
