#include "monty.h"

/**
 * custom_sub - Performs subtraction operation on the stack.
 * @stack_head: Pointer to the stack's head
 * @line_num: Line number
 *
 * Return: No return value
 */
void custom_sub(stack_t **stack_head, unsigned int line_num)
{
	stack_t *aux;
	int difference, nodes;

	aux = *stack_head;
	for (nodes = 0; aux != NULL; nodes++)
		aux = aux->next;
	if (nodes < 2)
	{
		fprintf(stderr, "L%d: Unable to sub, stack too short\n", line_num);
		fclose(bus.file);
		free(bus.content);
		custom_free_stack(*stack_head);
		exit(EXIT_FAILURE);
	}
	aux = *stack_head;
	difference = aux->next->n - aux->n;
	aux->next->n = difference;
	*stack_head = aux->next;
	free(aux);
}
