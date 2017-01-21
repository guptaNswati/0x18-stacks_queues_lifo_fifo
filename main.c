#include "monty.h"

/**
 * main - main function for monty byte code intepreter
 * @ac: command line argument count (should be 2)
 * @av: string array of command line arguments. av[1] should be file name
 * Return: 0 upon non-error exit
 */

int main(int ac, char *av[])
{
	int fd;

	arg_count(ac);
	av_check(av[1]);

	return (0);
}
