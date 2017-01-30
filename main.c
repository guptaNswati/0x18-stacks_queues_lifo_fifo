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
	size_t n = 1000, line = 1;
	char *cmd = NULL, *curr_cmd, *push_arg, *cc, *pa;
	int flag = 0, close_status;
	stack_t *head = NULL, *main_head;

	ac_check(ac);
	av_check(av[1]);
	f = fopen(av[1], "r");
	cmd = malloc(1000);
	curr_cmd = malloc(100);
	push_arg = malloc(10);
	if (push_arg == NULL || cmd == NULL || curr_cmd == NULL)
		malloc_fail(cmd, curr_cmd, NULL);
	pa = push_arg;
	cc = curr_cmd;
	while (-1 != getline(&cmd, &n, f))
	{
		curr_cmd = strtok(cmd, " \t\r\n\v\f");
		if (curr_cmd == NULL || curr_cmd[0] == '#' ||
		    strcmp("nop", curr_cmd) == 0)
		{
			line++;
			continue;
		}
		if (strcmp(curr_cmd, "push") == 0)
		{
			push_arg = strtok(NULL, " \t\r\n\v\f");
			push(&head, push_arg, &flag, line);
		}
		else
			instrction_caller(curr_cmd, line, &head, &flag);
		line++;
	}
	printf("addy trace: %p\n%p\n%p\n", cmd, cc, pa);
	if ((close_status = fclose(f)) != 0)
		free_all(cmd, cc, pa);
	else
		free_all(cmd, cc, pa);
	//printf("main_head: %p\n", main_head);
//	freelist(&main_head);
	return (0);
}
