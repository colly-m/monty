#include "monty.h"

/**
 * func_div - divides the second element by the top element of the stack
 * @h: head of the linked list
 * @nline: line number;
 * Return: no return
 */
void func_div(stack_t **h, unsigned int nline)
{
	int m, len = 0;
	stack_t *head;

	head = *h;

	while (head)
	{
		head = head->next;
		len++;
	}

	if (len < 2)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", nline);
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

	m = head->next->n / head->n;
	head->next->n = m;
	*h = head->next;
	free(head);
}
