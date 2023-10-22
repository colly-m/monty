#include "monty.h"

/**
 * func_pchar - function to print the char value of the first element
 * @h: head of the linked list
 * @nline: line number;
 * Return: no return
 */
void func_pchar(stack_t **h, unsigned int nline)
{
	if (h == NULL || *h == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", nline);
		fclose(glovar.fd);
		free(glovar.buffer);
		free_stack(h);
		exit(EXIT_FAILURE);
	}
	if ((*h)->n < 0 || (*h)->n >= 128)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", nline);
		fclose(glovar.fd);
		free(glovar.buffer);
		free_stack(h);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*h)->n);
}
