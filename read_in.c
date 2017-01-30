#include "monty.h"

/**
* push - executes a PUSH depending on mode (stack or queue mode)
* @head: pointer to head pointer of list
* @data: data for new node
* @flag: indicator of stack or queue mode
* @num: line number in monty file for error handling
* Return: nothing
**/
void push(stack_t **head, char *data, int *flag, unsigned int num)
{
	int i = 0, length = strlen(data);
	stack_t *main_head = *head;

	for (i = 0; i < length; i++)
	{
		if (data[i] < '0' || data[i] > '9')
		{
			printf("L%d: usage: push integer\n", num);
			freelist(head);
			exit(EXIT_FAILURE);
		}
	}
	if (*(flag) == 1)
		add_end(head, atoi(data));
	else /* stack mode */
		add_front(head, atoi(data));
	//free(data);
}

/**
* get_op_code - finds a valid opcode
* @cmd: function to search for
* Return: pointer to valid function or null
**/
void (*get_op_code(char *cmd))(stack_t **head, unsigned int num)
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

	for (i = 0; i < 13; i++)
	{
		if (strcmp(cmd, instructs[i].opcode) == 0)
			return (instructs[i].f);
	}
	return (NULL);
}

/**
* instrction_caller - finds and executes an instruction.
* @opcode: pointer to instruction
* @num: opcode line number
* @head: pointer to head pointer of stack_s list
* @flag: pointer to int for switching between stack and queue
* Return: nothing
**/
void instrction_caller(char *opcode, unsigned int num, stack_t **head,
		       int *flag)
{
	void (*f)(stack_t **, unsigned int);
	stack_t *main_head = *head;

	if (strcmp(opcode, "stack") == 0)
		*(flag) = 0;
	else if (strcmp(opcode, "queue") == 0)
		*(flag) = 1;
	else
	{
		f = get_op_code(opcode);
		if (f)
			f(head, num);
		else
		{
			printf("L%d: unknown instruction %s\n", num,
			       opcode);
			if (*head)
				freelist(head);
			exit(EXIT_FAILURE);
		}
	}
}
