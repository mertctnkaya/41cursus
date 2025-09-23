#include "../push_swap.h"

void sort_large(t_stack *s)
{
	int i;
	int j;
	int max_bits;
	int size;

	size = s->total_size;
	max_bits = 0;
	while (((size - 1) >> max_bits) != 0)
		max_bits++;
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if (((s->a->index >> i) & 1) == 1)
				ra(&s->a, 1);
			else
				pb(&s->a, &s->b, 1);
			j++;
		}
		while (s->size_b > 0)
			pa(&s->a, &s->b, 1);
		i++;
	}
}