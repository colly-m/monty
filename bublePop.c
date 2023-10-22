#include "monty.h"

/**
 * func_pop - function to remove the top element of the stack
 *
 * @h: head of the linked list
 * @nline: line number
 * Return: no return
 */
void func_pop(stack_t **h, unsigned int nline)
{
	stack_t *head;

	if (h == NULL || *h == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", nline);
		fclose(glovar.fd);
		free(glovar.buffer);
		free_stack(h);
		exit(EXIT_FAILURE);
	}
	head = *h;
	*h = head->next;
	free(head);
}
