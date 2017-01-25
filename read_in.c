#include "monty.h"

/**
* switch_mode - switches adding to list to stack or queue mode
* @head: pointer to head pointer of list
* @data: data for new node
* @flag: indicator of stack or queue mode
* Return: nothing
**/
void switch_mode(stack_s **head, int data, int *flag)
{
	/* if flag is on, list mode is in queue */
	if (*(flag) == 1)
		add_end(head, data);
	else /* stack mode */
		add_begining(head, data);
}

/**
* get_op_code - finds a valid opcode
* @opcode: function to search for
* Return: pointer to valid function or null
**/
instruction_t (*get_op_code(char *opcode))(stack_s **head, unsigned int num)
{
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
* instrction_caller - finds and executes an instruction.
* @opcode: pointer to instruction
* @num: opcode line number
* @head: pointer to head pointer of stack_s list
* @data: value of the new node
* @flag: pointer to int for switching between stack and queue
* Return: nothing
**/
void instrction_caller(char *opcode, unsigned int num, stack_s **head,
		       int data, int *flag)
{
	instruction_t (*func)(stack_s **, unsigned int);

	if (strcmp(opcode, "push") == 0)
		switch_mode(head, data, flag);
	else if (strcmp(opcode, "stack") == 0)
		*(flag) = 0;
	else if (strcmp(opcode, "queue") == 0)
		*(flag) = 1;
	else
	{
		func = get_op_code(opcode);
		if (func)
			func(head, num);
		else
		{
			printf("L%d: unknown instruction %s\n", num,
			       opcode);
			exit(EXIT_FAILURE);
		}
	}
}
