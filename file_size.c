#include "monty.h"

/**
 * file_size - gets the size of a file in bytes. NOT FOR USE ON BINARY files
 * @file: name or path of the file
 * Return: the
 */
int file_size(char *file)
{
	int len;
	FILE *f = fopen(file, "r");

	fseek(f, 0, SEEK_END);
	len = (int)ftell(f);
	fclose(f);
	return (len);
}
