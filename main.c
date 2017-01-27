#include "monty.h"

/**
 * main - main function for monty byte code intepreter
 * @ac: command line argument count (should be 2)
 * @av: string array of command line arguments. av[1] should be file name
 * Return: 0 upon non-error exit
 */

int main(int ac, char *av[])
{
	FILE *f;
	size_t n = 0, line = 1;
	char *cmd = NULL, *curr_cmd, *push_arg;
	int flag = 0;
	stack_t *head = NULL;

	/* Checks if argcount is valid and file can be opened  */
	ac_check(ac);
	av_check(av[1]);
	f = fopen(av[1], "r");
	while (-1 != getline(&cmd, &n, f))
	{
		curr_cmd = strtok(cmd, " ");
		printf("%s\n", curr_cmd);
		if (strcmp(curr_cmd, "push") == 0)
		{
			push_arg = strtok(NULL, " ");
			printf("%s\n", push_arg);
			push(&head, push_arg, &flag);
		}
		else if (curr_cmd[0] == '#' || strcmp(curr_cmd, "nop") == 0)
			continue;
		else
		{
			/* checks if given arg is a valid instruction or not*/
			instrction_caller(curr_cmd, line, &head, &flag);
		}
		line++;
	}
	free(cmd);
	free(curr_cmd);
	return (0);
}
