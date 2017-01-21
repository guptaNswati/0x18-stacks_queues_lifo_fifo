#include "monty.h"

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

void *av_check(char *av)
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

void malloc_fail()
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
