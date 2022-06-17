#include "monty.h"
/**
 * push - pushes an element to the stack
 * @stack: stack
 * @line_number: current line
 * Return: void
 */
void push(stack_t **stack, unsigned int line_number)
{
	char *val = gen.num;

	if ((is_num(val)) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
		return;
	}
	if (gen.check == 1)
	{
		if (!stacked(stack, atoi(gen.num)))
		{
			exit(EXIT_FAILURE);
			return;
		}
	}
	else
	{
		if (!queued(stack, atoi(gen.num)))
		{
			exit(EXIT_FAILURE);
			return;
		}
	}
}
/**
 * stacked - adds node on stack
 * @stack: stack
 * @num: argument to opcode
 * Return: void
 */
stack_t *stacked(stack_t **stack, const int num)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (!new_node)
	{
		free(new_node);
		return (NULL);
	}

	new_node->n = num;
	new_node->next = *stack;
	new_node->prev = NULL;
	if (*stack)
		(*stack)->prev = new_node;
	*stack = new_node;
	return (new_node);
}
/**
 * queued - adds  node
 * @stack: stack
 * @num: opccode argument
 * Return: void
 */
stack_t *queued(stack_t **stack, const int num)
{
	stack_t *new_node = malloc(sizeof(stack_t));
	stack_t *head = *stack;

	if (!new_node)
	{
		free(new_node);
		return (NULL);
	}
	new_node->n = num;

	if (!*stack)
	{
		new_node->next = NULL;
		new_node->prev = NULL;
		*stack = new_node;
		return (new_node);
	}

	while (head)
	{
		if (head->next)
		{
			head = head->next;
		}
		else
		{
			new_node->next = NULL;
			new_node->prev = NULL;
			head->next = new_node;
			break;
		}
	}
	return (new_node);
}
/**
 * is_num - checks if string is a number
 * @str: string to be checked
 * Return: 1
 */
int is_num(char *str)
{
	if (*str == '\0' || !str)
		return (0);
	if (*str == '-')
		str++;
	while (*str)
	{
		if (isdigit(*str) == 0)
			return (0);
		str++;
	}
	return (1);
}
