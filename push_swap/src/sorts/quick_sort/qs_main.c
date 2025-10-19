/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qs_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@42student.kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 20:09:52 by mecetink          #+#    #+#             */
/*   Updated: 2025/10/19 19:08:31 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../push_swap.h"

static void push_by_chunk(t_stack *s, int *target, int chunk)
{
	// target: işlenmeyi bekleyen en küçük sayı indexi 0, döngülü
	// chunka göre pushla
	// b ye atılmış ve geri alınması kolay hamle
	// gerektirmeyen parçalar oluşturmak
	if (s->a->index <= *target)
	{
		// stack a nın en üstündeki eleman targetten küçükse
		pb(s, 1);
		rb(&s->b, 1);
		// neden rb: en küçük elemanlar en alta giderek derin bi yerde toplanır
		// restore yaparken büyükleri üstte küçükleri alta koymak kolaylaştırır
		(*target)++; // ilerle
	}
	else if (s->a->index <= *target + chunk)
	{
		pb(s, 1);
		(*target)++;
	}
	else
	// target şu anki chunkın çok dışında büyük indexli
	// neden ra: bunu atla
		ra(&s->a, 1);
}

static void small_sort(t_stack *s)
{
	if (s->size_a == 2)
		sort_2(&s->a);
	else if (s->size_a == 3)
		sort_3(&s->a);
	else if (s->size_a == 4)
		sort_4(s);
	else if (s->size_a == 5)
		sort_5(s);
}

void quick_sort(t_stack *s)
{
	int target;
	int chunk;

	if (is_sorted(s->a))
		return;
	if (s->size_a <= 5)
	{
		small_sort(s);
		return;
	}
	if (s->total_size <= 100)
		chunk = 15;
	else
		chunk = 30;
	target = 0;
	while (s->size_a > 0)
		push_by_chunk(s, &target, chunk);
	restore_by_max(s);
}
