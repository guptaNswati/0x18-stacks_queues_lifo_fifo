#include "monty.h"

/**
* rot_lft - rotates the top of list by moving it end and shifting second to top.
* @head: pointer to head pointer of list
* @num: line number of opcode
* Return: nothing
**/
void rot_lft(stack_s **head, unsigned int num)
{
	int data;

	/* only no or 1 element, nothing to do*/
	if (!(*head || (*head)->next))
		return;
	data = (*head)->n;
	*head = (*head)->next;
	(*head)->prev = NULL;
	add_end(head, data);
}

/**
* rot_rgt - rotates the last element of stack_s list to top.
* @head: pointer to head pointer of list
* @num: line number of opcode
* Return: nothing
**/
void rot_rgt(stack_s **head, unsigned int num)
{
	/* only no or 1 element, nothing to do*/
        if (!(*head || (*head)->next))
                return;
	add_begining(head, remove_end(head));
}
