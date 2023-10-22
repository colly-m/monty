#include "monty.h"

/**
 * exec - function to select the correct opcode to perform
 * @h: pointer to head of the list
 * @curr: pointer to line counter
 * @buffer: pointer to content in a line
 * @fd: pointer to a file in monty
 *
 * Return: pointer to the function that executes the opcode
 */
int exec(char *buffer, stack_t **h, unsigned int curr, FILE *fd)
{
	instruction_t instruct[] = {
		{"push", func_push},
		{"pall", func_pall},
		{"pint", func_pint},
		{"pop", func_pop},
		{"swap", func_swap},
		{"queue", func_queue},
		{"stack", func_stack},
		{"add", func_add},
		{"nop", func_nop},
		{"sub", func_sub},
		{"mul", func_mul},
		{"div", func_div}, {"mod", func_mod}, {"pchar", func_pchar},
		{"pstr", func_pstr}, {"rotl", func_rotfirst},
		{"rotr", func_rotrev},
		{NULL, NULL}
	};
	unsigned int u = 0;
	char *ocode;

	ocode = _strtkn(buffer, " \t\n");
	if (ocode && ocode[0] == '#')
		return (0);
	glovar.arg = _strtkn(NULL, " \t\n");
	while (instruct[u].opcode && ocode)
	{
		if (_strcmp(ocode, instruct[u].opcode) == 0)
		{
			instruct[u].f(h, curr);
			return (0);
		}
		u++;
	}
	if (ocode && instruct[u].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instructions %s\n", curr, ocode);
		fclose(fd);
		free(buffer);
		free_stack(h);
		exit(EXIT_FAILURE); }
	return (1);
}
