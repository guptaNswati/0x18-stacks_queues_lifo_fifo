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
 * Return: value of fd
 *
 */

int av_check(char *av)
{
	int fd;

	fd = open(av, O_RDONLY);

	if (fd == -1)
	{
		printf("Error: can't open file %s\n", av);
		exit(EXIT_FAILURE);
	}
	return (fd);
}
