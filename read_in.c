#include "monty.h"

/**
 * read_in - reads monty file contents into buffer
 * @filename: name or path of file
 * Return: buffer containing contents of file
 *
 */

char **read_in(char *filename)
{
	int fd, fsize, i = 0;
	char *dbuffer, buf;
	ssize_t readcount;
	char **cmd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		av_check(filename);
	fsize = file_size(filename);
	dbuffer = malloc(fsize);
	if (dbuffer == NULL)
		malloc_fail();
	readcount = read(fd, dbuffer, (size_t)fsize);
	/**for (i = 0; dbuffer[i] != NULL; i++)
	{
		if (dbuffer[i] == " ")
			dbuffer[i]
	}
	this is a work in progress. Currently, trying to figure out
	how to best clean the buffer for operation code parsing.
	options: linked list of operations or array of strings of ops or
	just a straight up buffer string. Leaning towards either 1 or 3
	*/
	return (&dbuffer);
}
