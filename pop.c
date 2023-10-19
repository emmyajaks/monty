#include "monty.h"
/**
 * d_pop - this prints the top
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void d_pop(stack_t **head, unsigned int counter)
{
	stack_t *g;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	g = *head;
	*head = g->next;
	free(g);
}
