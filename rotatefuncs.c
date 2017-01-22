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

/**
* lifo - sets the format of the stack_s list to a stack order, last in first out.
* @head: pointer to head pointer of list
* @num: line number of opcode
* Return: nothing
**/
void lifo(stack_s **head, unsigned int num)
{
	add_begining();
}

/**
* fifo - sets the format of the stack_s list to a queue order (FIFO),
* first in first out.
* @head: pointer to head pointer of list
* @num: line number of opcode
* Return: nothing
**/
void fifo(stack_s **head, unsigned int num)
{
	add_end();
}

void switch_mode(stack_s **head, int data, int flag)
{
	/* if flag is on, list mode is in queue */
	if (flag)
		add_end(head, data);
	else
		add_begining(head, data);
}
