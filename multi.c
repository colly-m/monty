#include "monty.h"

/**
 * func_mul - multiplies the top element to the second top element of the stack
 * @h: head of the linked list
 * @nline: line number;
 * Return: no return
 */
void func_mul(stack_t **h, unsigned int nline)
{
	int m;
	stack_t *aux = NULL;

	aux = *h;

	for (m = 0; aux != NULL; aux = aux->next, m++)
		;

	if (m < 2)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", nline);
		fclose(glovar.fd);
		free(glovar.buffer);
		free_stack(h);
		exit(EXIT_FAILURE);
	}

	aux = (*h)->next;
	aux->n *= (*h)->n;
	func_pop(h, nline);
}
