#include "../push_swap.h"

void push_swap(t_stack *s)
{
	if (s->total_size <= 1)
		return;
	if (s->total_size == 2)
		sort_2(&s->a);
	else if (s->total_size == 3)
		sort_3(&s->a);
	else if (s->total_size == 4)
		sort_4(s);
	else if (s->total_size == 5)
		sort_5(s);
	else
		sort_large(s);
}