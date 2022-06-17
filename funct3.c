#include "monty.h"

/**
 * swap -  swaps data from top to previous
 * @stack: stack
 * @line_cnt: current line
 * Return: void
 */
void swap(stack_t **stack, unsigned int line_cnt)
{
	stack_t *tmp = NULL;
	int tmp_n = 0;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_cnt);
		exit(EXIT_FAILURE);
		return;
	}
	tmp = *stack;
	tmp_n = tmp->n;
	tmp->n = tmp_n;

	tmp->n = tmp->next->n;
	tmp->next->n = tmp_n;

}
/**
 * add -  adds the first two nodes of the stack
 * @stack: stack
 * @line_cnt: current line
 *
 * Return: void
 */
void add(stack_t **stack, unsigned int line_cnt)
{
	int result;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_cnt);
		exit(EXIT_FAILURE);
		return;
	}

	result = ((*stack)->next->n) + ((*stack)->n);
	pop(stack, line_cnt);
	(*stack)->n = result;
}
/**
 * nop - inserts "lazy song"
 * @stack: rest
 * @line_cnt: hmmmmmm
 * Return: void
 */
void nop(stack_t **stack, unsigned int line_cnt)
{
	(void) stack;
	(void) line_cnt;
}
/**
 * sub -  substracts the first two nodes of the stack
 * @stack: stack
 * @line_cnt: current line
 * Return: void
 */
void sub(stack_t **stack, unsigned int line_cnt)
{
	int result;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_cnt);
		exit(EXIT_FAILURE);
		return;
	}

	result = ((*stack)->next->n) - ((*stack)->n);
	pop(stack, line_cnt);
	(*stack)->n = result;
}
/**
 * _div - divides the next top value by the top value
 * @stack: stack
 * @line_cnt: current line
 * Return: void
 */
void _div(stack_t **stack, unsigned int line_cnt)
{
	int result;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_cnt);
		exit(EXIT_FAILURE);
		return;
	}
	if (((*stack)->n) == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_cnt);
		exit(EXIT_FAILURE);
		return;
	}

	result = ((*stack)->next->n) / ((*stack)->n);
	pop(stack, line_cnt);
	(*stack)->n = result;
}
