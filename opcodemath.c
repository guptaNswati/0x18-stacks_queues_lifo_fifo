#include "monty.h"

/**
* add_tops - adds the top two elements of the stack_t list if list is
* two elements or long and stores result in second top, removes top.
* @head: pointer to head pointer of stack_t list.
* @num: line number of opcode
* Return: nothing
**/
void add_tops(stack_t **head, unsigned int num)
{
	stack_t *tmp;

	if (!head || !(*head) || !(*head)->next)
	{
		printf("L%d: can't add, stack too short\n", num);
		freelist(head);
		exit(EXIT_FAILURE);
	}
	tmp = *head;
	*head = (*head)->next;
	(*head)->prev = NULL;
	(*head)->n += tmp->n;
	free(tmp);
}

/**
* sub_tops - subtracts the top element from second top element of the stack_t
* list if its two elements or long, stores result in second and removes top.
* two elements or long.
* @head: pointer to head pointer of stack_t list.
* @num: line number of opcode
* Return: nothing
**/
void sub_tops(stack_t **head, unsigned int num)
{
	stack_t *tmp;

	if (!head || !(*head) || !(*head)->next)
	{
		printf("L%d: can't sub, stack too short\n", num);
		exit(EXIT_FAILURE);
	}
	tmp = *head;
	*head = (*head)->next;
	(*head)->prev = NULL;
	(*head)->n -= tmp->n;
	free(tmp);
}

/**
* div_tops - divides second top two element by top element of the stack_t list,
* if its two elemets or long, stores result in second and removes top.
* two elements or long.
* @head: pointer to head pointer of stack_t list.
* @num: line number of opcode
* Return: nothing
**/
void div_tops(stack_t **head, unsigned int num)
{
	stack_t *tmp;

	if (!head || !(*head) || !(*head)->next)
	{
		printf("L%d: can't div, stack too short\n", num);
		exit(EXIT_FAILURE);
	}
	if ((*head)->n == 0)
	{
		printf("L%d: division by zero\n", num);
		exit(EXIT_FAILURE);
	}
	tmp = *head;
	*head = (*head)->next;
	(*head)->prev = NULL;
	(*head)->n /= tmp->n;
	free(tmp);
}

/**
* mul_tops - multiplies the top two elements of the stack_t list if list is
* two elements or long, stores result in second and removes top.
* @head: pointer to head pointer of stack_t list.
* @num: line number of opcode
* Return: nothing
**/
void mul_tops(stack_t **head, unsigned int num)
{
	stack_t *tmp;

	if (!head || !(*head) || !(*head)->next)
	{
		printf("L%d: can't mul, stack too short\n", num);
		exit(EXIT_FAILURE);
	}
	tmp = *head;
	*head = (*head)->next;
	(*head)->prev = NULL;
	(*head)->n *= tmp->n;
	free(tmp);
}

/**
* mod_tops - calculates the mod of top two elements of the stack_t list if,
* list is two elements or long, stores result in second and removes top.
* two elements or long.
* @head: pointer to head pointer of stack_t list.
* @num: line number of opcode
* Return: nothing
**/
void mod_tops(stack_t **head, unsigned int num)
{
	stack_t *tmp;

	if (!head || !(*head) || !(*head)->next)
	{
		printf("L%d: can't mod, stack too short\n", num);
		exit(EXIT_FAILURE);
	}
	if ((*head)->n == 0)
	{
		printf("L%d: division by zero\n", num);
		exit(EXIT_FAILURE);
	}
	tmp = *head;
	*head = (*head)->next;
	(*head)->prev = NULL;
	(*head)->n %= tmp->n;
	free(tmp);
}
