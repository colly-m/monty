#include "monty.h"

global_t glovar;

/**
* main - monty code interpreter, entry point
* @argc: pointer to argument counts
* @argv: monty file argument vectors
* Return: 0 on success
*/
int main(int argc, char *argv[])
{
	char *buffer;
	FILE *fd;
	size_t size = 0;
	ssize_t read_line = 1;
	stack_t *head = NULL;
	unsigned int curr = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(argv[1], "r");
	glovar.fd = fd;
	if (!fd)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (read_line > 0)
	{
		buffer = NULL;
		read_line = getline(&buffer, &size, fd);
		glovar.buffer = buffer;
		curr++;
		if (read_line > 0)
		{
			exec(buffer, &head, curr, fd);
		}
		free(buffer);
	}
	free_stack(&head);
	fclose(fd);
return (0);
}
