#include "monty.h"

/**
 * func_mod - function to compute the rest of the division
 * of the second element by the top element of the stack
 * @h: head of the linked list
 * @nline: line number;
 * Return: no return
 */
void func_mod(stack_t **h, unsigned int nline)
{
	int m = 0, aux;
	stack_t *head;

	head = *h;
	while (head)
	{
		head = head->next;
		m++;
	}

	if (m < 2)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", nline);
		fclose(glovar.fd);
		free(glovar.buffer);
		free_stack(h);
		exit(EXIT_FAILURE);
	}
	head = *h;
	if (head->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", nline);
		fclose(glovar.fd);
		free(glovar.buffer);
		free_stack(h);
		exit(EXIT_FAILURE);
	}

	aux = head->next->n % head->n;
	head->next->n = aux;
	*h = head->next;
	free(head);
}
