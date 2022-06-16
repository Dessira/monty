#include "monty.h"
/**
 * pall - prints all the values on the stack
 * @stack: stack
 * @line_cnt: current line
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_cnt __attribute__((unused)))
{
	print(*stack);
}
/**
 * print - prints stack
 * @stack: stack to be printed
 * Return: stack size
 */
int print(stack_t *stack)
{
	size_t size;

	while (stack)
	{
		printf("%d\n", stack->n);
		stack = stack->next;
		size++;
	}
	return (size);
}
/**
 * pint - prints the value at the top of the stack, followed by a new line
 * @stack: stack to be printed
 * @line_cnt: current line
 * Return: void
 */
void pint(stack_t **stack, unsigned int line_cnt)
{
	if (!(*stack) || !stack)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_cnt);
		exit(EXIT_FAILURE);
		return;
	}
	printf("%d\n", (*stack)->n);
}
/**
 * pop - removes the top element of the stack
 * @stack: stack to be removed
 * @line_cnt: current line
 * Return: void
 */
void pop(stack_t **stack, unsigned int line_cnt)
{
	stack_t *new = NULL;

	if (stack == NULL || *stack == NULL)
	{
		line_cnt++;
		fprintf(stderr, "L%d: can't pop an empty stack", line_cnt);
		exit(EXIT_FAILURE);
	}
	new = (*stack)->next;
	free(*stack);
	*stack = new;
	if (!*stack)
		return;
	(*stack)->prev = NULL;
}
