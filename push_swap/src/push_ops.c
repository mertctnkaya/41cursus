#include "../push_swap.h"

void pa(t_node **a, t_node **b, int print)
{
	t_node *temp;

	if (!*b)
		return;
	temp = *b;
	*b = (*b)->next;
	if (*b)
		(*b)->prev = NULL;
	temp->next = *a;
	if (*a)
		(*a)->prev = temp;
	*a = temp;
	if (print)
		write(1, "pa\n", 3);
}

void pb(t_node **a, t_node **b, int print)
{
	t_node *temp;

	if (!*a)
		return;
	temp = *a;
	*a = (*a)->next;
	if (*a)
		(*a)->prev = NULL;
	temp->next = *b;
	if (*b)
		(*b)->prev = temp;
	*b = temp;
	if (print)
		write(1, "pb\n", 3);
}