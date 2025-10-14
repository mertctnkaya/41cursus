/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@42student.kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 20:09:52 by mecetink          #+#    #+#             */
/*   Updated: 2025/10/14 23:57:12 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	sort_small_a(t_stack *s, int size)
{
    int top;
    int mid;
    int bot;

    if (size <= 1 || is_sorted(s->a))
        return ;
    if (size == 2)
    {
        if (s->a->index > s->a->next->index)
            sa(&s->a, 1);
        return ;
    }
    top = s->a->index;
    mid = s->a->next->index;
    bot = s->a->next->next->index;
    if (top < mid && mid > bot && top < bot)
    {
        rra(&s->a, 1);
        sa(&s->a, 1);
    }
    else if (top > mid && mid < bot && top < bot)
        sa(&s->a, 1);
    else if (top < mid && mid > bot && top > bot)
        rra(&s->a, 1);
    else if (top > mid && mid < bot && top > bot)
        ra(&s->a, 1);
    else if (top > mid && mid > bot)
    {
        sa(&s->a, 1);
        rra(&s->a, 1);
    }
}

static void	sort_small_b(t_stack *s, int size)
{
    if (size == 0)
        return ;
    if (size == 1)
    {
        pa(&s->a, &s->b, 1);
        s->size_a++;
        s->size_b--;
        return ;
    }
    if (size == 2)
    {
        if (s->b && s->b->next && s->b->index < s->b->next->index)
            sb(&s->b, 1);
        pa(&s->a, &s->b, 1);
        pa(&s->a, &s->b, 1);
        s->size_a += 2;
        s->size_b -= 2;
        return ;
    }
    /* size == 3: önce maksimumu A'ya al, kalan ikiliyi düzelt, sonra ikisini daha A'ya al */
    if (s->b->index >= s->b->next->index && s->b->index >= s->b->next->next->index)
    {
        pa(&s->a, &s->b, 1);
        s->size_a++;
        s->size_b--;
    }
    else if (s->b->next->index >= s->b->index && s->b->next->index >= s->b->next->next->index)
    {
        sb(&s->b, 1);
        pa(&s->a, &s->b, 1);
        s->size_a++;
        s->size_b--;
    }
    else
    {
        /* üçüncü eleman maksimum: rb; sb; pa; rrb ile derin elemanları bozmadan işle */
        rb(&s->b, 1);
        sb(&s->b, 1);
        pa(&s->a, &s->b, 1);
        s->size_a++;
        s->size_b--;
        rrb(&s->b, 1);
    }
    /* kalan 2 eleman B'de: büyük üste gelsin */
    if (s->b && s->b->next && s->b->index < s->b->next->index)
        sb(&s->b, 1);
    pa(&s->a, &s->b, 1);
    pa(&s->a, &s->b, 1);
    s->size_a += 2;
    s->size_b -= 2;
}

// static void	sort_small(t_stack *s)
// {
// 	if (s->size_a == 2)
// 		sort_2(&s->a);
// 	else if (s->size_a == 3)
// 		sort_3(&s->a);
// 	else if (s->size_a == 4)
// 		sort_4(s);
// 	else if (s->size_a == 5)
// 		sort_5(s);
// }

/* quick_partition.c */

void	partition(t_stack *s, int pivot, int size)
{
	int	i;
	int	threshold;
    int	rotated;

	threshold = pivot - (size / 4); /* heuristic: pivot-12.5% */
    i = 0;
    rotated = 0;
	while (i < size)
	{
		if (s->a->index <= pivot)
		{
			pb(&s->a, &s->b, 1);
			s->size_a--;
			s->size_b++;
			/* eğer yeni üst elemana göre çok küçükse, rb ile aşağı at */
			if (s->b && s->b->index <= threshold)
				rb(&s->b, 1);
		}
		else
        {
            ra(&s->a, 1);
            rotated++;
        }
		i++;
	}
    while (rotated-- > 0)
        rra(&s->a, 1);
}


static void	rotate_b_to_top(t_stack *s, int pos)
{
	int	moves;

	if (pos <= s->size_b / 2)
	{
		while (pos-- > 0)
			rb(&s->b, 1);
	}
	else
	{
		moves = s->size_b - pos;
		while (moves-- > 0)
			rrb(&s->b, 1);
	}
}

void	restore_sorted_from_b(t_stack *s)
{
	int	pos;
	int	min_pos;

	while (s->size_b > 0)
	{
		pos = find_min_pos(s->b);
		rotate_b_to_top(s, pos);
		pa(&s->a, &s->b, 1);
		s->size_a++;
		s->size_b--;
		ra(&s->a, 1);
	}
	if (is_sorted(s->a))
		return ;
	min_pos = find_min_pos(s->a);
	if (min_pos <= s->size_a / 2)
	{
		while (min_pos-- > 0)
			ra(&s->a, 1);
	}
	else
	{
		min_pos = s->size_a - min_pos;
		while (min_pos-- > 0)
			rra(&s->a, 1);
	}
}

int	find_max_pos(t_item *stack)
{
	int	pos;
	int	max_pos;
	int	max;
	t_item *cur;

	if (!stack)
		return (0);
	cur = stack;
	max = cur->index;
	max_pos = 0;
	pos = 0;
	while (cur)
	{
		if (cur->index > max)
		{
			max = cur->index;
			max_pos = pos;
		}
		cur = cur->next;
		pos++;
	}
	return (max_pos);
}

void	restore_by_max(t_stack *s)
{
	int	pos;

	while (s->size_b > 0)
	{
		pos = find_max_pos(s->b);
		rotate_b_to_top(s, pos);
		pa(&s->a, &s->b, 1);
		s->size_a++;
		s->size_b--;
	}
	if (!is_sorted(s->a))
	{
		int min_pos = find_min_pos(s->a);
		if (min_pos <= s->size_a / 2)
			while (min_pos-- > 0)
				ra(&s->a, 1);
		else
		{
			min_pos = s->size_a - min_pos;
			while (min_pos-- > 0)
				rra(&s->a, 1);
		}
	}
}

static void	partition_a_to_b(t_stack *s, int pivot, int size, int *pushed_to_b)
{
    int i;
    int rotated;
    int threshold;

    threshold = pivot - (size / 4);
    i = 0;
    rotated = 0;
    *pushed_to_b = 0;
    while (i < size)
    {
        if (s->a->index <= pivot)
        {
            pb(&s->a, &s->b, 1);
            s->size_a--;
            s->size_b++;
            (*pushed_to_b)++;
            if (s->b && s->b->index <= threshold)
                rb(&s->b, 1);
        }
        else
        {
            ra(&s->a, 1);
            rotated++;
        }
        i++;
    }
    while (rotated-- > 0)
        rra(&s->a, 1);
}

static void	partition_b_to_a(t_stack *s, int pivot, int size, int *pushed_to_a)
{
    int i;
    int rotated;

    i = 0;
    rotated = 0;
    *pushed_to_a = 0;
    while (i < size)
    {
        if (s->b->index > pivot)
        {
            pa(&s->a, &s->b, 1);
            s->size_a++;
            s->size_b--;
            (*pushed_to_a)++;
        }
        else
        {
            rb(&s->b, 1);
            rotated++;
        }
        i++;
    }
    while (rotated-- > 0)
        rrb(&s->b, 1);
}

static void	quicksort_a(t_stack *s, int size)
{
    int pivot;
    int pushed;

    if (size <= 1 || is_sorted(s->a))
        return ;
    if (size <= 3)
        return (sort_small_a(s, size));
    pivot = get_pivot(s->a, size);
    partition_a_to_b(s, pivot, size, &pushed);
    quicksort_a(s, size - pushed);
    quicksort_b(s, pushed);
}

static void	quicksort_b(t_stack *s, int size)
{
    int pivot;
    int pushed;

    if (size <= 0)
        return ;
    if (size <= 3)
        return (sort_small_b(s, size));
    pivot = get_pivot(s->b, size);
    partition_b_to_a(s, pivot, size, &pushed);
    quicksort_a(s, pushed);
    quicksort_b(s, size - pushed);
}

void	quick_sort(t_stack *s)
{
    int target;
    int chunk;

    if (is_sorted(s->a))
        return ;
    if (s->size_a <= 5)
    {
        if (s->size_a == 2)
            sort_2(&s->a);
        else if (s->size_a == 3)
            sort_3(&s->a);
        else if (s->size_a == 4)
            sort_4(s);
        else if (s->size_a == 5)
            sort_5(s);
        return ;
    }
    /* chunk tabanlı dağıtım */
    chunk = (s->total_size <= 100) ? 15 : 30;
    target = 0;
    while (s->size_a > 0)
    {
        if (s->a->index <= target)
        {
            pb(&s->a, &s->b, 1);
            s->size_a--; s->size_b++;
            rb(&s->b, 1);
            target++;
        }
        else if (s->a->index <= target + chunk)
        {
            pb(&s->a, &s->b, 1);
            s->size_a--; s->size_b++;
            target++;
        }
        else
            ra(&s->a, 1);
    }
    /* B'den maksimumları geri al */
    restore_by_max(s);
}
