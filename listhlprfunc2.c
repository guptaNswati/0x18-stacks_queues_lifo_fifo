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
* print_list - prints stack_s list.
* @head: pointer to head pointer to stack_s list
* Return: nothing
**/
void printlist(stack_s **head)
{
	stack_s *tmp;

	if (!head || !(*head))
		return;
	tmp = *head;
	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
