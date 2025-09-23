#include "../push_swap.h"

static void bring_to_top(t_node **a, int index, int size_a)
{
	int pos;
	t_node *temp;

	pos = 0;
	temp = *a;
	while (temp)
	{
		if (temp->index == index)
			break;
		temp = temp->next;
		pos++;
	}
	if (pos <= size_a / 2)
	{
		while (pos-- > 0)
			ra(a, 1);
	}
	else
	{
		while (pos++ < size_a)
			rra(a, 1);
	}
}

void sort_4(t_stack *s)
{
	if (is_sorted(s->a))
		return;
	bring_to_top(&s->a, 3, s->size_a);
	pb(&s->a, &s->b, 1);
	s->size_a--;
	s->size_b++;
	sort_3(&s->a);
	pa(&s->a, &s->b, 1);
	s->size_a++;
	s->size_b--;
	ra(&s->a, 1);
}

void sort_5(t_stack *s)
{
	bring_to_top(&s->a, 0, s->size_a);
	pb(&s->a, &s->b, 1);
	s->size_a--;
	s->size_b++;
	bring_to_top(&s->a, 1, s->size_a);
	pb(&s->a, &s->b, 1);
	s->size_a--;
	s->size_b++;
	sort_3(&s->a);
	pa(&s->a, &s->b, 1);
	s->size_a++;
	s->size_b--;
	pa(&s->a, &s->b, 1);
	s->size_a++;
	s->size_b--;
}