#include "monty.h"

/**
 * free_stack - function to free a doubly linked list
 * @h: pointer to the head of the list
 * Return: void
 */
void free_stack(stack_t **h)
{
	stack_t *aux;

	aux = *h;
	while (h)
	{
		aux = (*h)->next;
		free(h);
		h = &aux;
	}
}
