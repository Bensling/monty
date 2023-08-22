#include "monty.h"

/**
 * cstm_pall - Prints the stack
 * 
 * @head: Header stack
 * @counter: no used
 * Return: no return
 */
void cstm_pall(stack_t **head, unsigned int counter)
{
	stack_t *h;
	(void)counter;

	h = *head;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
