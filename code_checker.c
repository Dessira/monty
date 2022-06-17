#include "monty.h"
/**
 * check - checks and matches opcode
 * @stack: stack
 * @str: string holding opcode
 * @line_number: current line
 * Return: void
 **/

void check(stack_t **stack, char *str, unsigned int line_number)
{
	int i = 0;
	instruction_t code[] = {

		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};
	if (!strcmp(str, "queue"))
	{
		gen.check = 0;
		return;
	}
	if (!strcmp(str, "stack"))
	{
		gen.check = 1;
		return;
	}

	while (code[i].opcode)
	{
		if (strcmp(code[i].opcode, str) == 0)
		{
			code[i].f(stack, line_number);
			return;

		}
		i++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, str);
	exit(EXIT_FAILURE);
}
