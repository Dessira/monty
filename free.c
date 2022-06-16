#include "monty.h"
/**
 * free_all - frees linked lists and buffers
 * @stack: stack
 * @buf: buffer from main
 * Return: void
 */
void free_all(stack_t *stack, char *buf)
{
	stack_t *head = stack;
	stack_t *next;

	if (stack)
	{
		next = stack->next;
		while (head)
		{
			free(head);
			head = next;
			if (next)
				next = next->next;
		}
	}
	free(buf);
}
