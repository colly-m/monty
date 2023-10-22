#include "monty.h"

/**
 * func_rotfirst - function to rotate the first element to the bottom
 * and  the second to the top
 * @h: head of the linked list
 * @nline: line number;
 * Return: no return
 */
void func_rotfirst(stack_t **h, unsigned int nline)
{
	stack_t *aux1 = NULL;
	stack_t *aux2 = NULL;
	(void)nline;

	if (*h == NULL)
		return;

	if ((*h)->next == NULL)
		return;

	aux1 = (*h)->next;
	aux2 = *h;

	for (; aux2->next != NULL; aux2 = aux2->next)
		;

	aux1->prev = NULL;
	aux2->next = *h;
	(*h)->next = NULL;
	(*h)->prev = aux2;
	*h = aux1;
}
