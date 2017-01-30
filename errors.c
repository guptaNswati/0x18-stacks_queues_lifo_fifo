#include "monty.h"

/**
 * freelist - frees doubly linked list
 * @head: pointer to beginning of list
 * Return: void
 */
void freelist(stack_t **head)
{
	stack_t *curr = *head, *prev;

	if (*head == NULL)
		return;
	while (curr->prev != NULL)
		curr = curr->prev;
	prev = curr->prev;
	while (curr->next != NULL)
	{
		curr = curr->next;
		prev = curr->prev;
		free(prev);
	}
	free(curr);
	*head = NULL;
}


/**
 * ac_check - checks if arg count is correct value
 * @ac: count of arguments
 * Return: void
 *
 */

void ac_check(int ac)
{
	if (ac != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
}


/**
 * av_check - checks if file was opened successfully
 * @av: string containing filename or file path
 * Return: void
 *
 */

void av_check(char *av)
{
	int fd;

	fd = open(av, O_RDONLY);

	if (fd == -1)
	{
		printf("Error: can't open file %s\n", av);
		exit(EXIT_FAILURE);
	}
	close(fd);
}

/**
 * malloc_fail - prints and exits when malloc fails
 *
 * Return: void
 */

void malloc_fail(char *s1, char *s2, char *s3)
{
	if (s1 != NULL)
		free(s1);
	if (s2 != NULL)
		free(s2);
	if (s3 != NULL)
		free(s3);
	printf("Error: malloc failed\n");
	exit(EXIT_FAILURE);
}

/**
 * free_all - frees the  char arrays created in main
 *
 * Return: void
 */

void free_all(char *s1, char *s2, char *s3)
{
	if (s1 != NULL)
		free(s1);
	if (s2 != NULL)
		free(s2);
	if (s3 != NULL)
		free(s3);
}
