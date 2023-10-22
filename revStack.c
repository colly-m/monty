#include "monty.h"

/**
 * func_rotrev - function to reverse the stack
 * @h: head of the linked list
 * @nline: line number
 * Return: no return
 */
void func_rotrev(stack_t **h, unsigned int nline)
{
	stack_t *aux = NULL;
	(void)nline;

	if (*h == NULL)
		return;

	if ((*h)->next == NULL)
		return;

	aux = *h;

	for (; aux->next != NULL; aux = aux->next)
		;

	aux->prev->next = NULL;
	aux->next = *h;
	aux->prev = NULL;
	(*h)->prev = aux;
	(*h) = aux;
}
