#include <stdio.h>
#include "monty.h"
/**
 * main - main block
 * @argc: number of arguments
 * @argv: arguments
 * Return: 0
 */
int main(int argc, char *argv[])
{
	int j = 1;
	FILE *mon;
	char *block = NULL, *contents = NULL;
	size_t size = 8;
	stack_t *stack = NULL;

	gen.check = 1;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	mon = fopen(argv[1], "r");
	if (mon == NULL)
	{
		fprintf(stderr, "ERROR: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (getline(&contents, &size, mon) != -1)
	{
		if (*contents == '\n')
		{
			j++;
			continue;
		}
		block = strtok(contents, " \t\n");

		if (!block || *block == '#')
		{
			j++;
			continue;
		}
		gen.num = strtok(NULL, " \t\n");
		check(&stack, block, j);
		j++;
	}
	fclose(mon);
	free_all(stack, contents);
	return (EXIT_SUCCESS);
}
