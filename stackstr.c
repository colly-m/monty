#include "monty.h"

/**
 * func_pstr - function to print the string of the stack
 * @h: head of the linked list
 * @nline: line number;
 * Return: void
 */
void func_pstr(stack_t **h, unsigned int nline)
{
	stack_t *aux;
	(void)nline;

	aux = *h;

	while (aux && aux->n > 0 && aux->n < 128)
	{
		printf("%c", aux->n);
		aux = aux->next;
	}

	printf("\n");
}
