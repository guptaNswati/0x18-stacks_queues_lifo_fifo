#include "monty.h"

/**
* rot_lft - rotates the top of list by moving it end and shifting second to top.
* @head: pointer to head pointer of list
* @num: line number of opcode
* Return: nothing
**/
void rot_lft(stack_t **head, unsigned int num)
{
	int data;
	(void)num;

	/* only no or 1 element, nothing to do*/
	if (!(*head || (*head)->next))
		return;
	data = (*head)->n;
	*head = (*head)->next;
	(*head)->prev = NULL;
	add_end(head, data);
}

/**
* rot_rgt - rotates the last element of stack_t list to top.
* @head: pointer to head pointer of list
* @num: line number of opcode
* Return: nothing
**/
void rot_rgt(stack_t **head, unsigned int num)
{
	(void)num;
	/* only no or 1 element, nothing to do*/
        if (!(*head || (*head)->next))
                return;
	add_front(head, remove_end(head));
}
