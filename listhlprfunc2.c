#include "monty.h"

/**
* get_node_end- returns the last node of the stack_s list.
* @head: pointer to head pointer to stack_s list.
* Return: last node of the list
**/
stack_s *get_node_end(stack_s **head)
{
	stack_s *tmp;

	if (!head || !(*head))
		return (NULL);
	if (!(*head)->next)
		return (*head);
	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);

}

/**
* print_top - prints top element of the stack_s list.
* @head: pointer to head pointer to stack_s list
* @num: line number of opcode
* Return: nothing
**/
void print_top(stack_s **head, int num)
{

	if (*head)
		printf("%d\n", (*head)->n);
	else
		printf("L<%d>: can't print, stack empty\n", num);
		exit(EXIT_FAILURE);
}


/**
* print_list - prints stack_s list.
* @head: pointer to head pointer to stack_s list
* Return: nothing
**/
void print_list(stack_s **head)
{
	stack_s *tmp;

	if (!(head || *head))
		return;
	tmp = *head;
	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
