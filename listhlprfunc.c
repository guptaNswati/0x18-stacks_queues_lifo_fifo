/* since head will be an extern variable, so may not need to pass*/

stack_s **add_begining(stack_s **head, int data)
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
