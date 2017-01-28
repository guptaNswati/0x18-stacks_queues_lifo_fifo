#include "monty.h"

/**
 * freelist - frees doubly linked list
 * @head: pointer to beginning of list
 * Return: void
 */
void freelist(stack_t *head)
{
	stack_t *curr = head, *prev;

	if (head == NULL)
		return;
	while (curr->prev != NULL)
		curr = curr->prev;
	prev = curr->prev;
	while (curr->next != NULL)
	{
		curr = curr->next;
		prev = curr->prev;
		free(prev);
	}
	free(curr);
	head = NULL;
}


/**
 * ac_check - checks if arg count is correct value
 * @ac: count of arguments
 * Return: void
 *
 */

void ac_check(int ac)
{
	if (ac != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
}


/**
 * av_check - checks if file was opened successfully
 * @av: string containing filename or file path
 * Return: void
 *
 */

void av_check(char *av)
{
	int fd;

	fd = open(av, O_RDONLY);

	if (fd == -1)
	{
		printf("Error: can't open file %s\n", av);
		exit(EXIT_FAILURE);
	}
	close(fd);
}

/**
 * malloc_fail - prints and exits when malloc fails
 *
 * Return: void
 */

void malloc_fail(void)
{
	printf("Error: malloc failed\n");
	exit(EXIT_FAILURE);
}

/**
 * invalid_instruction - error handler for invalid instruction
 * @line_number: int line number indicating which line number caused failure
 * @opcode: string containing unknown operational code
 * Return: void
 */

void invalid_instruction(int line_number, char *opcode)
{
	printf("L%d: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}
