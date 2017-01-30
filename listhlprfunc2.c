#include "monty.h"

/**
* get_node_end- returns the last node of the stack_t list.
* @head: pointer to head pointer to stack_t list.
* Return: last node of the list
**/
stack_t *get_node_end(stack_t **head)
{
	stack_t *tmp;

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
* print_top - prints top element of the stack_t list.
* @head: pointer to head pointer to stack_t list
* @num: line number of opcode
* Return: nothing
**/
void print_top(stack_t **head, unsigned int num)
{
	(void)num;

	if (*head)
		printf("%d\n", (*head)->n);
	else
	{
		printf("L%d: can't pint, stack empty\n", num);
		exit(EXIT_FAILURE);
	}
}


/**
* print_list - prints stack_t list.
* @head: pointer to head pointer to stack_t list
* @num: line number of opcode
* Return: nothing
**/
void print_list(stack_t **head, unsigned int num)
{
	stack_t *tmp;
	(void)num;

	if (!head || !(*head))
		return;
	tmp = *head;
	while (tmp)
	{
		printf("%d\n", tmp->n);
		printf("address:%p\n", tmp);
		tmp = tmp->next;
	}
	freelist(head);
}
