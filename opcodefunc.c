#include "monty.h"

instruction_t *get_op_code(char *opcode)
{
	/* push, nop, comment */
	instruction_t instructs[] = {
		{"pall", print_list},
		{"pint", print_top},
		{"pop", remove_top},
		{"swap", swap_tops},
		{"add", add_tops},
		{"sub", sub_tops},
		{"div", div_tops},
		{"mul", mul_tops},
		{"mod", mod_tops},
		{"pchar", chr_top},
		{"pstr", str_top},
		{"rotl", rot_lft},
		{"rotr", rot_rgt},
		{"stack", lifo},
		{"queue", fifo},
		{NULL, NULL}
	};
	int i;

	for (i = 0; i < 15;i++)
	{
		if (strcmp(instructs[i].opcode, opcode) == 0)
			return (instructs[i].f);
	}
	return (NULL);
}

/**
* swap_tops - swaps the top two elements of the stack_s list if list is
* two elements or long.
* @head: pointer to head pointer of stack_s list.
* @num: line number of opcode
* Return: nothing
**/
void swap_tops(stack_s **head, int num)
{
	int tmp;

	if (!(*head || head || (*head)->next))
	{
		printf("L<%d>: can't swap, stack too short\n", num);
		exit(EXIT_FAILURE);
	}
	tmp = (*head)->n;
	(*head)->n = *head->next->n;
	(*head)->next->n = tmp;
}
