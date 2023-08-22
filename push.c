#include "monty.h"

/**
 * custom_push - Adds a node to the stack.
 * @stack_head: Pointer to the stack's head
 * @line_num: Line number
 *
 * Return: No return value
 */
void custom_push(stack_t **stack_head, unsigned int line_num)
{
	int n, j = 0, flag = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			j++;
		for (; bus.arg[j] != '\0'; j++)
		{
			if (bus.arg[j] > 57 || bus.arg[j] < 48)
				flag = 1;
		}
		if (flag == 1)
		{
			fprintf(stderr, "L%d: Usage: push integer\n", line_num);
			fclose(bus.file);
			free(bus.content);
			custom_free_stack(*stack_head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: Usage: push integer\n", line_num);
		fclose(bus.file);
		free(bus.content);
		custom_free_stack(*stack_head);
		exit(EXIT_FAILURE);
	}
	n = atoi(bus.arg);
	if (bus.lifi == 0)
		add_node(stack_head, n);
	else
		add_queue(stack_head, n);
}
