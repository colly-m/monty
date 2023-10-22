#ifndef MONTY_H_
#define MONTY_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


/**
 * struct global_s - global structure to use in the functions
 * @lifo: is stack or queue
 * @curr: current line
 * @arg: second parameter inside the current line
 * @head: doubly linked list
 * @fd: file descriptor
 * @buffer: input text
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct global_s
{
	int lifo;
	unsigned int curr;
	char  *arg;
	char *lines;
	stack_t *head;
	FILE *fd;
	char *buffer;
} global_t;


extern global_t glovar;


void func_push(stack_t **h, unsigned int nline);
void func_pall(stack_t **h, unsigned int nline);
void func_pint(stack_t **h, unsigned int nline);
void func_pop(stack_t **h, unsigned int nline);
void func_swap(stack_t **h, unsigned int nline);
void func_queue(stack_t **h, unsigned int nline);
void func_stack(stack_t **h, unsigned int nline);
void func_add(stack_t **h, unsigned int nline);
void func_nop(stack_t **h, unsigned int nline);
void func_sub(stack_t **h, unsigned int nline);
void func_div(stack_t **h, unsigned int nline);
void func_mul(stack_t **h, unsigned int nline);
void func_mod(stack_t **h, unsigned int nline);
void func_pchar(stack_t **h, unsigned int nline);
void func_pstr(stack_t **h, unsigned int nline);
void func_rotfirst(stack_t **h, unsigned int nline);
void func_rotrev(stack_t **h, unsigned int nline);


void (*get_opcodes(char *code))(stack_t **stack, unsigned int line_number);

ssize_t getline(char **lineptr, size_t *n, FILE *fd);

int checkz_chr(char *str, char ch);
char *_strtkn(char *str, char *d);
void *_realloc(void *ptr, unsigned int o_size, unsigned int nw_size);
void *_calloc(unsigned int numelm, unsigned int size);
int _strcmp(char *s1, char *s2);

void addnode(stack_t **head, int n);

void free_stack(stack_t **h);

void addz_queue(stack_t **h, int n);
stack_t *addz_initdnodeint(stack_t **h, int n);
void freez_dlist(stack_t *head);


int exec(char *buffer, stack_t **h, unsigned int curr, FILE *fd);

void free_glovar(void);
void init_glovar(FILE *fd);
FILE *exist_check(int argc, char *argv[]);
void process_line(const char *line, int curr);

#endif
