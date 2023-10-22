#include "monty.h"

/**
 * func_sub - function to subtracts the top element to the second top
 * element of the stack
 * @h: head of the linked list
 * @nline: line number
 * Return: void
 */
void func_sub(stack_t **h, unsigned int nline)
{
	int m, g;
	stack_t *aux;

	aux = *h;

	for (m = 0; aux != NULL; m++)
		aux = aux->next;

	if (m < 2)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", nline);
		fclose(glovar.fd);
		free(glovar.buffer);
		free_stack(h);
		exit(EXIT_FAILURE);
	}

	aux = *h;
	g = aux->next->n - aux->n;
	aux->next->n = g;
	*h = aux->next;
	free(aux);
}
