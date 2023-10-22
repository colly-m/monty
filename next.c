#include "monty.h"

/**
 * func_queue - prints the top
 * @h: stack head
 * @nline: pointer to line-number
 * Return: no return
*/
void func_queue(stack_t **h, unsigned int nline)
{
	(void)h;
	(void)nline;
	glovar.lifo = 1;
}

/**
 * addz_queue - add node to the tail stack
 * @n: new_value
 * @h: head of the stack
 * Return: no return
*/
void addz_queue(stack_t **h, int n)
{
	stack_t *nw_node, *aux;

	aux = *h;
	nw_node = malloc(sizeof(stack_t));
	if (nw_node == NULL)
	{
		printf("Error\n");
	}
	nw_node->n = n;
	nw_node->next = NULL;
	if (aux)
	{
		while (aux->next)
			aux = aux->next;
	}
	if (!aux)
	{
		*h = nw_node;
		nw_node->prev = NULL;
	}
	else
	{
		aux->next = nw_node;
		nw_node->prev = aux;
	}
}
