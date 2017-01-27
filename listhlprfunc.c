#include "monty.h"
/* since head will be an extern variable, so may not need to pass*/

/**
* add_begining - add a new node in the begining of stack_t list.
* @head: pointer to head pointer of the list
* @data: new node data
* Return: address of new node
**/
stack_t *add_begining(stack_t **head, int data)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		return (NULL);

	new->n = data;
	new->prev = NULL;
	new->next = *head;
	(*head)->prev = new;
	*head = new;
	return (new);
}

/**
* add_end - add a new node in the end of stack_t list.
* @head: pointer to head pointer of the list
* @data: new node data
* Return: address of new node
**/
stack_t *add_end(stack_t **head, int data)
{
	stack_t *new, *tmp;

	new = malloc(sizeof(stack_t));
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
* remove_begining - removes a node from the begining of the stack_t list.
* @head: pointer to head pointer of the list
* Return: nothing
**/
void remove_top(stack_t **head)
{
	stack_t *tmp;

	if (!(*head || head))
		return;
	tmp = *head;
	if (tmp->next)
	{
		*head = (*head)->next;
		(*head)->prev = NULL;
	}
	free(tmp);
}

/**
* remove_end - removes a node from the end of the stack_t list.
* @head: pointer to head pointer of the list
* Return: value of last node
**/
int remove_end(stack_t **head)
{
	stack_t *tmp;
	int value;

	/* function called only when there are more than two elements in list */
	if (!(*head)->next)
	{
		value = (*head)->n;
		free(*head);
	}
	else
	{
		tmp = *head;
		while (tmp->next)
			tmp = tmp->next;
		value = tmp->n;
		tmp->prev->next = NULL;
		free(tmp);
	}
	return (value);
}
