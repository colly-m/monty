#include "monty.h"

/**
 * func_pall - function to print the stack
 * @h: pointer to head of the list
 * @nline: no used
 * Return: no return
*/
void func_pall(stack_t **h, unsigned int nline)
{
	stack_t *head;
	(void)nline;

	head = *h;
	if (head == NULL)
		return;
	while (head)
	{
		printf("%d\n", head->n);
		head = head->next;
	}
}
