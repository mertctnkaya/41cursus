/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@42student.kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 14:31:06 by mecetink          #+#    #+#             */
/*   Updated: 2025/09/23 14:31:41 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h> // malloc, free, exit
#include <unistd.h> // write

// Yığın düğümü yapısı (bağlı liste)
// 'index' alanı, sıralama algoritması için hayati önem taşır.
typedef struct s_node
{
	int value;			 // Orijinal tamsayı değeri
	int index;			 // Sıralanmış pozisyonu (en küçük: 0, en büyük: N-1)
	struct s_node *prev; // Önceki düğüm
	struct s_node *next; // Sonraki düğüm
} t_node;

// Programın ana yapısı (global değişken yasağına uymak için)
typedef struct s_stack
{
	t_node *a; // A yığınının başı
	t_node *b; // B yığınının başı
	int size_a;
	int size_b;
	int total_size;
} t_stack;

// Hata yönetimi (validation.c)
void ft_error(void);

// Yığın Oluşturma ve Doğrulama (validation.c)
t_node *parse_and_create_stack(int argc, char **argv, int *size);
void assign_index(t_node **stack, int size);
int is_sorted(t_node *stack);

// Temel Yığın İşlemleri
// swaps.c
void sa(t_node **a, int print);
void sb(t_node **b, int print);
void ss(t_node **a, t_node **b, int print);

// pushes.c
void pa(t_node **a, t_node **b, int print);
void pb(t_node **a, t_node **b, int print);

// rotates.c
void ra(t_node **a, int print);
void rb(t_node **b, int print);
void rr(t_node **a, t_node **b, int print);

// reverse_rotates.c
void rra(t_node **a, int print);
void rrb(t_node **b, int print);
void rrr(t_node **a, t_node **b, int print);

// Sıralama Algoritmaları
// small_sort.c
void handle_small_sort(t_stack *s);
void sort_2(t_node **a); // small_sort.c içinde statik değil
void sort_3(t_node **a);

// medium_sort.c
void sort_4(t_stack *s);
void sort_5(t_stack *s);

// large_sort.c
void sort_large(t_stack *s);

// Ana Sıralama Kontrolü (sort_main.c)
void push_swap(t_stack *s);

// Bellek Yönetimi (main.c)
void free_stack(t_node *stack);

#endif