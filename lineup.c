#include "monty.h"

/**
 * func_stack - function to set the format fo the data to a stack (LIFO)
 * @h: head of the linked list
 * @nline: line number
 * Return: void
 */
void func_stack(stack_t **h, unsigned int nline)
{
	(void)h;
	(void)nline;

	glovar.lifo = 1;
}
