#include "monty.h"

/**
* add_front - add a new node in the begining of stack_t list.
* @head: pointer to head pointer of the list
* @data: new node data
* Return: address of new node
**/
stack_t *add_front(stack_t **head, int data)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		printf("Error: malloc failed\n");
		freelist(head);
		exit(EXIT_FAILURE);
	}
	new->n = data;
	new->prev = NULL;
	if (*head == NULL)
		new->next = NULL;
	else
		new->next = *head;
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
	{
		printf("Error: malloc failed\n");
		freelist(head);
		exit(EXIT_FAILURE);
	}
	new->n = data;
	new->prev = NULL;
	new->next = NULL;
	if (!(*head))
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
* remove_top - removes a node from the begining of the stack_t list.
* @head: pointer to head pointer of the list
* @num: line number of instruction from monty file
* Return: nothing
**/
void remove_top(stack_t **head, unsigned int num)
{
	stack_t *tmp;
	(void)num;

	if (!head || !(*head))
	{
		printf("L%d: can't pop an empty stack\n", num);
		exit(EXIT_FAILURE);
	}
	if ((*head)->next)
	{
		tmp = *head;
		*head = (*head)->next;
		(*head)->prev = NULL;
		free(tmp);
	}
	else
	{
		free(*head);
		*head = NULL;
	}
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
