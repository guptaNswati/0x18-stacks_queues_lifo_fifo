#include "monty.h"

instruction_t *get_op_code(char *opcode)
{
	/* seperate: push, nop, comment */
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
		{NULL, NULL}
	};
	int i;

	for (i = 0; i < 13;i++)
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

/**
* chr_top - prints the char at the top of the stack_s list if its in ascii range
* and list is not empty.
* @head: pointer to head pointer of list
* @num: line number of opcode
* Return: nothing
**/
void chr_top(stack_s **head, int num)
{
	if (!(*head || head))
	{
		printf("L<%d>: can't pchar, stack empty\n", num);
		exit(EXIT_FAILURE);
	}
	if ((*head)->n < 0 || (*head)->n > 127)
	{
		printf("L<%d>: can't pchar, value out of range\n", num);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*head)->n);
}

/**
* str_top - prints the string starting at the top of the stack_s list, if
* its not empty and values are in ascii range.
* @head: pointer to head pointer of list
* @num: line number of opcode
* Return: nothing
**/
void str_top(stack_s **head, int num)
{
	stack_s *tmp;

	if (*head)
	{
		tmp = *head;
		while (tmp && (tmp->n > 0 && tmp->n < 128))
		{
			printf("%c", tmp->n);
			tmp = tmp->next;
		}
	}
	printf("\n");
}
