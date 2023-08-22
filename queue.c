#include "monty.h"

/**
 * custom_queue - Changes the mode to queue (FIFO).
 * @stack_head: Pointer to the stack's head
 * @line_num: Line number
 *
 * Return: No return value
 */
void custom_queue(stack_t **stack_head, unsigned int line_num)
{
	(void)stack_head;
	(void)line_num;
	bus.lifi = 1;
}

/**
 * add_queue - Adds a node to the tail of the stack.
 * @stack_head: Pointer to the head of the stack
 * @n: New value for the node
 *
 * Return: No return value
 */
void add_queue(stack_t **stack_head, int n)
{
	stack_t *new_node, *aux;

	aux = *stack_head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
	}
	new_node->n = n;
	new_node->next = NULL;
	if (aux)
	{
		while (aux->next)
			aux = aux->next;
	}
	if (!aux)
	{
		*stack_head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		aux->next = new_node;
		new_node->prev = aux;
	}
}
