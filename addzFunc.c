#include "monty.h"

/**
 * addnode - function to add node to the head stack
 * @head: pointer to head of the stack
 * @n: new_value
 * Return: no return
*/
void addnode(stack_t **head, int n)
{
	stack_t *nw_node, *aux;

	aux = *head;
	nw_node = malloc(sizeof(stack_t));
	if (nw_node == NULL)
	{ printf("Error\n");
		exit(0); }
	if (aux)
		aux->prev = nw_node;
	nw_node->n = n;
	nw_node->next = *head;
	nw_node->prev = NULL;
	*head = nw_node;
}
