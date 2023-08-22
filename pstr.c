#include "monty.h"

/**
 * cus_pstr - Prints the string starting at the top of the stack,
 *               followed by a newline.
 * @stack_head: Pointer to the stack's head
 * @counter: Line number
 *
 * Return: No return value
 */
void cus_pstr(stack_t **stack_head, unsigned int counter)
{
	stack_t *stack_ptr;
	(void)counter;

	stack_ptr = *stack_head;
	while (stack_ptr)
	{
		if (stack_ptr->n > 127 || stack_ptr->n <= 0)
		{
			break;
		}
		printf("%c", stack_ptr->n);
		stack_ptr = stack_ptr->next;
	}
	printf("\n");
}

