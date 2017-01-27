#include "monty.h"

void push(int data)
{
	stack_s *new, *tmp;

	new = malloc(sizeof(stack_s));
	if (new == NULL)
		return (NULL);

	new->n = data;
	new->prev = NULL;
	new->next = NULL;
	if(*head == NULL)
		*head = new;
	else if ((*head)->next == NULL)
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
	return;
}
