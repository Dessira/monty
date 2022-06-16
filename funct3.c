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
