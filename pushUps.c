#include "monty.h"

/**
 * func_push - add node to the stack
 * @h: stack head
 * @nline: pointer to line-number
 * Return: no return
*/
void func_push(stack_t **h, unsigned int nline)
{
	int n, j = 0, k = 0;

	if (glovar.arg)
	{
		if (glovar.arg[0] == '-')
			j++;
		for (; glovar.arg[j] != '\0'; j++)
		{
			if (glovar.arg[j] > 57 || glovar.arg[j] < 48)
				k = 1; }
		if (k == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", nline);
			fclose(glovar.fd);
			free(glovar.buffer);
			free_stack(h);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", nline);
		fclose(glovar.fd);
		free(glovar.buffer);
		free_stack(h);
		exit(EXIT_FAILURE); }
	n = atoi(glovar.arg);
	if (glovar.lifo == 0)
		addnode(h, n);
	else
		addz_queue(h, n);
}
