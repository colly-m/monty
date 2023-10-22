#include "monty.h"

/**
 * func_pint - function to print the value at the top of the stack
 * @h: head of the linked list
 * @nline: line number
 * Return: no return
 */
void func_pint(stack_t **h, unsigned int nline)
{
	(void)nline;

	if (*h == NULL)
	{
		fprintf(stderr, "L%u: ", nline);
		fprintf(stderr, "can't pint, stack empty\n");
		fclose(glovar.fd);
		free(glovar.buffer);
		free_stack(h);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*h)->n);
}
