#include "monty.h"
/**
 * d_add - this adds the top two elements of the stack.
 * @head: the stack head
 * @counter: the line_number
 * Return: no return
*/
void d_add(stack_t **head, unsigned int counter)
{
	stack_t *g;
	int len = 0, aux;

	g = *head;
	while (g)
	{
		g = g->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	g = *head;
	aux = g->n + g->next->n;
	g->next->n = aux;
	*head = g->next;
	free(g);
}
