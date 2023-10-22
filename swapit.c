#include "monty.h"

/**
 * func_swap - function to swap the top two elements of the stack
 * @h: head of the linked list
 * @nline: line number
 * Return: no return
 */
void func_swap(stack_t **h, unsigned int nline)
{
	int m = 0;
	stack_t *aux = NULL;

	aux = *h;

	for (; aux != NULL; aux = aux->next, m++)
		;

	if (m < 2)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", nline);
		fclose(glovar.fd);
		free(glovar.buffer);
		free_stack(h);
		exit(EXIT_FAILURE);
	}

	aux = *h;
	*h = (*h)->next;
	aux->next = (*h)->next;
	aux->prev = *h;
	(*h)->next = aux;
	(*h)->prev = NULL;
}
