#include "monty.h"

/**
 * execute - executes the opcode
 * @stack: head linked list - stack
 * @counter: line_counter
 * @file: poiner to monty file
 * @content: line content
 * Return: no return
 */
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t opst[] = {
		{"push", custom_push}, {"pall", cstm_pall}, {"pint", c_pint},
		{"pop", c_pop},
		{"swap", custom_swap},
		{"add", custom_add},
		{"nop", cus_nop},
		{"sub", custom_sub},
		{"div", custom_div},
		{"mul", custom_mul},
		{"mod", custom_mod},
		{"pchar", custom_pchar},
		{"pstr", cus_pstr},
		{"rotl", c_rotl},
		{"rotr", c_rotr},
		{"queue", custom_queue},
		{"stack", custom_stack},
		{NULL, NULL}
	};
	unsigned int i = 0;
	char *op;

	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{opst[i].f(stack, counter);
			return (0);
		}
		i++;
	}
	if (op && opst[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
		fclose(file);
		free(content);
		custom_free_stack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}
