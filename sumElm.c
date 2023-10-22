#include "monty.h"

/**
 * func_add - function to add the top two elements of the stack
 * @h: head of the linked list
 * @nline: line number
 * Return: void
 */
void func_add(stack_t **h, unsigned int nline)
{
	int m, aux;
	stack_t *head;

	head = *h;

	while (head)
	{
		head = head->next;
		m++;
	}
	if (m < 2)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", nline);
		fclose(glovar.fd);
		free(glovar.buffer);
		free_stack(h);
		exit(EXIT_FAILURE);
	}

	head = *h;
	aux = head->n + head->next->n;
	head->next->n = aux;
	*h = head->next;
	free(head);
}
