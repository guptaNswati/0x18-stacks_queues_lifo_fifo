#include "monty.h"

/**
 * validator - checks to see if instruction is valid opcode or not
 * @opcode: incoming operator
 * @line_number: line number from file for error handling
 * Return: void
 */

void validator(char *opcode, int line_number)
{
	int i = 0, total = 0;
	instruction_t *inst;
	instruction_t valid[] = {
		{"pall", pall}, {"pint", pint}, {"pop", pop}, {"swap", swap},
		{"add", add}, {"nop", nop}, {"sub", sub}, {"div", div},
		{"mul", mul}, {"mod", mod}, {"pchar", pchar}, {"pstr", pstr},
		{"rotl", rotl}, {"rotr", rotr}, {NULL, NULL}
	};

	while (i < 15)
	{
		if (strcmp(opcode, valid[i][0]) == 0)
			return (inst[i].f);
		i++;
	}
	if (total == 0 && i != 0)
		invalid_instruction(line_number, opcode);
	return;
}
