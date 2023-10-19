#include "monty.h"
/**
 * d_pstr - prints the string starting at the top of the stack,
 * followed by a new
 * @head: the stack head
 * @counter: the line_number
 * Return: no return
*/
void d_pstr(stack_t **head, unsigned int counter)
{
	stack_t *g;
	(void)counter;

	g = *head;
	while (g)
	{
		if (g->n > 127 || g->n <= 0)
		{
			break;
		}
		printf("%c", g->n);
		g = g->next;
	}
	printf("\n");
}
