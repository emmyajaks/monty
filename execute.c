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
				{"push", d_push}, {"pall", d_pall}, {"pint", d_pint},
				{"pop", d_pop},
				{"swap", d_swap},
				{"add", d_add},
				{"nop", d_nop},
				{"sub", d_sub},
				{"div", d_div},
				{"mul", d_mul},
				{"mod", d_mod},
				{"pchar", d_pchar},
				{"pstr", d_pstr},
				{"rotl", d_rotl},
				{"rotr", d_rotr},
				{"queue", d_queue},
				{"stack", d_stack},
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
		{	opst[i].f(stack, counter);
			return (0);
		}
		i++;
	}
	if (op && opst[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}
