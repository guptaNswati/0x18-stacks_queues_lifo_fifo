#include "monty.h"
/* since head will be an extern variable, so may not need to pass*/

/**
* add_begining - add a new node in the begining of stack_s list.
* @head: pointer to head pointer of the list
* @data: new node data
* Return: address of new node
**/
stack_s *add_begining(stack_s **head, int data)
{
	stack_s *new;

	new = malloc(sizeof(stack_s));
	if (new == NULL)
		return (NULL);

	new->n = data;
	new->prev = NULL;
	new->next = *head;
	*head->prev = new;
	*head = new;
	return (new);
}

/**
* add_begining - add a new node in the end of stack_s list.
* @head: pointer to head pointer of the list
* @data: new node data
* Return: address of new node
**/
stack_s **add_end(stack_s **head, int data)
{
	stack_s *new, *tmp;

	new = malloc(sizeof(stack_s));
	if (new == NULL)
		return (NULL);

	new->n = data;
	new->prev = NULL;
	new->next = NULL;
	if(!(*head))
		*head = new;
	else if (!(*head)->next)
	{
		(*head)->next = new;
		new->prev = *head;
	}
	else
	{
		tmp = *head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		new->prev = tmp;
	}
	return (new);
}

/**
* remove_begining - removes a node from the begining of the stack_s list
* and returns it.
* @head: pointer to head pointer of the list
* Return: removed node
**/
stack_s *remove_begining(stack_s **head)
{
	stack_s *tmp;

	if (!head || !(*head))
		return;
	tmp = *head;
	if (tmp->next)
	{
		*head = (*head)->next;
		(*head)->prev = NULL;
	}
	return (tmp);
}

/**
* remove_end - removes a node from the end of the stack_s list.
* @head: pointer to head pointer of the list
* Return: nothing
**/
void remove_end(stack_s **head)
{
	stack_s *tmp;

	if (!head || !(*head))
                return;

	if (!(*head)->next)
		free(*head);
	else
	{
		tmp = *head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->prev->next = NULL;
		free(tmp);
	}
}
